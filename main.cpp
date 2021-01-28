
#include <iostream>
#include <cstring>
#include "input.h"
#include "ip.h"
#include "port.h"


using namespace std;



int main(int argc, char **argv){
	
	if (check_args(argc,argv) != 0){
		return 0;
	}

	
	String mask(argv[1]);
	
	String *sub_mask;
	size_t sizes;

	mask.split("=", &sub_mask, &sizes);
	String *kind;
	size_t kindes;

	sub_mask[0].split("-", &kind, &kindes);	
	String compare = kind[1].trim();

	if(compare.equals(String("ip"))){
	Ip mask_ip(sub_mask[0].trim());
	mask_ip.set_value(sub_mask[1].trim());
	parse_input(mask_ip);
	
	}else if(compare.equals(String("port"))){
		Port mask_port(sub_mask[0].trim());
		mask_port.set_value(sub_mask[1].trim());
		parse_input(mask_port);
	}

	delete []sub_mask;
	delete []kind;
    return 0;
}




