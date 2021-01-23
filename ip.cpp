#include <stddef.h>
#include <iostream>
#include "string.h"
#include "field.h"
#include "ip.h"
#include <bitset>
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

	if (sizes != 4){
		delete []subPackets;
		delete []packet;
		return false;
	}

	unsigned int tmp = 0;
	int shifter = 24;
	for(int i = 0; i < 4; i++){
		cout<<"tmp is: "<<bitset<32>(tmp)<<endl;
		int seg = subPackets[i].trim().to_integer();
		cout<<"seg is: "<<seg<<endl;
		tmp += (seg << shifter);
		shifter -= 8;		
	}

	shifter = 31;
	unsigned int lowFilter = 0;
	unsigned int highFilter = 0xFFFFFFFF;
	for(int i = 0; i < packet[1].trim().to_integer(); i++){
		lowFilter += (0x1 << shifter);
		highFilter = (highFilter >> 1);
		shifter -= 1;		
	}

	
	low = tmp & lowFilter;
	high = low + highFilter;
	cout<<"the low is: "<<bitset<32>(low)<<", and the high is: "<< bitset<32>(high)<<endl;
	cout<<"the low is: "<<low<<", and the high is: "<< high<<endl;
	delete []subPackets;
	delete []packet;

	return true;
}

bool Ip::match_value(String val) const{

	char delimiters = '.';
	String *subPackets;
	size_t sizes;

	val.split(&delimiters, &subPackets, &sizes);

	if (sizes != 4){
		delete []subPackets;
		return false;
	}

	unsigned int value = 0;
	int shifter = 24;
	for(int i = 0; i < 4; i++){
		cout<<"value is: "<<bitset<32>(value)<<endl;
		int seg = subPackets[i].trim().to_integer();
		cout<<"seg is: "<<seg<<endl;
		value += (seg << shifter);
		shifter -= 8;		
	}
	

	if (value >= low && value <= high){
		delete []subPackets;
		return true;
	}
	delete []subPackets;
	return false;
}