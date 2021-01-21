#include <stddef.h>
#include <iostream>
#include "string.h"
#include "field.h"
#include "ip.h"

using namespace std;


Ip::Ip(String pattern):Field(pattern, IP){
	cout<<"IP was created"<<endl;
}

bool Ip::set_value(String val){

	char delimiters = '/';
	String *packet;
	size_t packs = 0;

	val.split(&delimiters, &packet, &packs);

	if (packs != 2){
		delete []packet;
		return false;
	}

	delimiters = '.';
	String *subPackets;
	size_t sizes;

	packet[0].split(&delimiters, &subPackets, &sizes);

	if (sizes != 2){
		delete []subPackets;
		delete []packet;
		return false;
	}

	unsigned int tmp = 0;
	int shifter = 24;
	for(int i = 0; i < 4; i++){
		int seg = subPackets[i].to_integer();
		tmp += (seg << shifter);
		shifter -= 8;		
	}

	shifter = 24;
	unsigned int lowFilter = 0;
	unsigned int highFilter = 0xFFFFFFFF;
	for(int i = 0; i < packet[1].to_integer(); i++){
		lowFilter += (0x1 << shifter);
		highFilter = (highFilter >> 1);
		shifter -= 1;		
	}

	
	low = tmp & shifter;
	high = low + highFilter;

	delete []subPackets;
	delete []packet;

	return true;
}

bool Ip::match_value(String val) const{
	unsigned int value = (unsigned int)val.to_integer();

	if (value > low && value < high){
		return true;
	}
	return false;
}