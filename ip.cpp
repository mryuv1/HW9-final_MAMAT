#include <stddef.h>
#include <iostream>
#include "string.h"
#include "field.h"
#include "ip.h"

using namespace std;


Ip::Ip(String pattern):Field(pattern, IP){}

bool Ip::set_value(String val){
	String *packet;
	size_t packs = 0;

	val.split("/", &packet, &packs);

	if (packs != 2){
		delete []packet;
		return false;
	}


	String *sub_packets;
	size_t sizes;

	packet[0].split(".", &sub_packets, &sizes);

	if (sizes != 4){
		delete []sub_packets;
		delete []packet;
		return false;
	}

	unsigned int tmp = 0;
	int shifter = 24;
	for(int i = 0; i < 4; i++){
		String pack = sub_packets[i].trim();
		int seg = pack.to_integer();
		tmp += (seg << shifter);
		shifter -= 8;		
	}

	shifter = 31;
	unsigned int low_filter = 0;
	unsigned int high_filter = 0xFFFFFFFF;
	String count = packet[1].trim();
	int counter = count.to_integer();
	for(int i = 0; i < counter; i++){
		low_filter += (0x1 << shifter);
		high_filter = (high_filter >> 1);
		shifter -= 1;		
	}

	
	low = tmp & low_filter;
	high = low + high_filter;

	delete []sub_packets;
	delete []packet;

	return true;
}

bool Ip::match_value(String val) const{
	String *sub_packets;
	size_t sizes;
	val.split(".", &sub_packets, &sizes);
	if (sizes != 4){
		delete []sub_packets;
		return false;
	}
	unsigned int value = 0;
	int shifter = 24;
	for(int i = 0; i < 4; i++){
	
		int seg = sub_packets[i].to_integer();
		value += (seg << shifter);
		shifter -= 8;		
	}
	if (value >= low && value <= high){
		delete []sub_packets;
		
		return true;
	}
	delete []sub_packets;
	return false;
}
