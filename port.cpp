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

	//cout<<"the size in PORT _ SET-VALUE IS:----------"<<size<<endl;
	if (size != 2){
		delete []output;
	//	cout<<"GOT------------------OUT"<<endl;
		return false;
	}

	String check1 = output[0].trim();
	String check2 = output[1].trim();
	range[0] =check1.to_integer();
	range[1] = check2.to_integer();

	//cout<<"the range is from----------"<<range[0]<<"------------to---------"<<range[1]<<endl;
	delete []output;

	return true; //need to check what if 0-0?
}

bool Port::match_value(String val) const{
	int value = val.to_integer();

	//cout<<"the value is----------"<<value<<endl;
	//cout<<"AND THE RANGE IS ---------"<<range[0]<<"__TO---------"<<range[1]<<endl;

	if (value >= range[0] && value <=range[1]){
		return true;
	}
	return false;
}