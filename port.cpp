#include <stddef.h>
#include <iostream>
#include "strings.h"
#include "field.h"
#include "port.h"

using namespace std;

Port::Port(String pattern): Field(pattern, PORT){
	cout<<"port was created"<<endl;
}

bool Port::set_value(String val){

	char delimiters = '-';
	String *output;
	size_t size = 0;

	val.split(&delimiters, &output, &size);

	if (size != 2){
		delete []output;
		return false;
	}

	range[0] =output[0].to_integer();
	range[1] = output[1].to_integer();

	delete []output;

	return true; //need to check what if 0-0?
}

bool Port::match_value(String val) const{
	int value = val.to_integer();

	if (value > range[0] && value < range[1]){
		return true;
	}
	return false;
}