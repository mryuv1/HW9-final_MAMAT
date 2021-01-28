#include <stddef.h>
#include <iostream>
#include "strings.h"
#include "field.h"
#include "port.h"

using namespace std;

Port::Port(String pattern): Field(pattern, PORT){
}

bool Port::set_value(String val){
	String *output;
	size_t size = 0;

	val.split("-", &output, &size);
	if (size != 2){
		delete []output;
		return false;
	}
	String check1 = output[0].trim();
	String check2 = output[1].trim();
	range[0] =check1.to_integer();
	range[1] = check2.to_integer();
	delete []output;

	return true; 
}

bool Port::match_value(String val) const{
	int value = val.to_integer();
	if (value >= range[0] && value <=range[1]){
		return true;
	}
	return false;
}
