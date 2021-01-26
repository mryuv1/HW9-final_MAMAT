#include <stddef.h>
#include <iostream>
#include "string.h"
#include "field.h"
#include "ip.h"
#include <bitset>
using namespace std;


Ip::Ip(String pattern):Field(pattern, IP){
}

bool Ip::set_value(String val){

	//cout<<"SET VALUE IP--------------------"<<endl;
	String *packet;
	size_t packs = 0;

	val.split("/", &packet, &packs);

	if (packs != 2){
		//cout<<"packs arenot 2-------------"<<endl;
		delete []packet;
		return false;
	}


	String *subPackets;
	size_t sizes;

	packet[0].split(".", &subPackets, &sizes);

	if (sizes != 4){
	//	cout<<"sizes arenot 4-------------"<<endl;
		delete []subPackets;
		delete []packet;
		return false;
	}

	unsigned int tmp = 0;
	int shifter = 24;
	for(int i = 0; i < 4; i++){
	//	cout<<"tmp is: "<<bitset<32>(tmp)<<endl;
		String pack = subPackets[i].trim();
		int seg = pack.to_integer();
	//	cout<<"seg is: "<<seg<<endl;
		tmp += (seg << shifter);
		shifter -= 8;		
	}

	shifter = 31;
	unsigned int lowFilter = 0;
	unsigned int highFilter = 0xFFFFFFFF;
	String count = packet[1].trim();
	int counter = count.to_integer();
	for(int i = 0; i < counter; i++){
		lowFilter += (0x1 << shifter);
		highFilter = (highFilter >> 1);
		shifter -= 1;		
	}

	
	low = tmp & lowFilter;
	high = low + highFilter;
	//cout<<"the low is: "<<bitset<32>(low)<<", and the high is: "<< bitset<32>(high)<<endl;
	//cout<<"the low is: "<<low<<", and the high is: "<< high<<endl;
	delete []subPackets;
	delete []packet;

	return true;
}

bool Ip::match_value(String val) const{

	String *subPackets;
	size_t sizes;
	//cout<<"LAST OPTION__________________-"<<endl;
	val.split(".", &subPackets, &sizes);

	if (sizes != 4){
		delete []subPackets;
		return false;
	}

	unsigned int value = 0;
	int shifter = 24;
	for(int i = 0; i < 4; i++){
	
		int seg = subPackets[i].to_integer();
	//	cout<<"seg is: "<<seg<<endl;
		value += (seg << shifter);
		shifter -= 8;		
	}
	
		//cout<<"value is: "<<bitset<32>(value)<<endl;
	if (value >= low && value <= high){
		delete []subPackets;
		
		return true;
	}
	delete []subPackets;
	return false;
}