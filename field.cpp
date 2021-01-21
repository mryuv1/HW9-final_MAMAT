#include <stddef.h>
#include <iostream>
#include "strings.h"
#include "ip.h"
#include "port.h"
#include "field.h"

Field::Field(String pattern, field_type type):pattern(pattern), type(type){}

Field::Field(String pattern):pattern(pattern),type(GENERIC){}

Field::~Field(){}

field_type Field::get_type() const{
	return type;
}

bool Field::set_value(String val){
	if(type == IP){
		return ((Ip*)this)->set_value(val);
	}else if (type == PORT){
		return ((Port*)this)->set_value(val);
	}

	return false;
}
 bool Field::match_value(String val) const{
 	if(type == IP){
		return ((Ip*)this)->match_value(val);
	}else if (type == PORT){
		return ((Port*)this)->match_value(val);
	}

	return false;
 }

 bool Field::match(String packet){

 	char delimiters = ',';
	String *output;
	size_t size = 0;

	packet.split(&delimiters, &output, &size);

	delimiters = '=';

	if (type == IP){

		String *ipfirst;
		String *ipSecond;
		size_t ipFirstSize = 0;
		size_t ipSecondSize = 0;

		output[0].split(&delimiters, &ipfirst, &ipFirstSize);
		output[1].split(&delimiters, &ipSecond, &ipSecondSize);
		bool first = match_value(ipfirst[1]);
		bool second = match_value(ipSecond[1]); //we may need ot use trim

		delete []output;
		delete []ipfirst;
		delete []ipSecond;
		return (first || second); // its enough that one of them is a match

	}else if(type == PORT){

		String *portfirst;
		String *portSecond;
		size_t portFirstSize = 0;
		size_t portSecondSize = 0;

		output[2].split(&delimiters, &portfirst, &portFirstSize);
		output[3].split(&delimiters, &portSecond, &portSecondSize);
		bool first = match_value(portfirst[1]);
		bool second = match_value(portSecond[1]); //we may need ot use trim

		delete []output;
		delete []portfirst;
		delete []portSecond;
		return (first || second);
	}

	return false;

 }