#include <stddef.h>
#include <iostream>
#include "strings.h"
#include "ip.h"
#include "port.h"
#include "field.h"

using namespace std;

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
	String *new_output;
	size_t size = 0;	
	packet.split(",", &new_output, &size);	
	bool result = false;
	String *field;
			
		for(unsigned int i = 0; i < size ; i++){
			size_t field_size = 0;
			new_output[i].split("=", &field, &field_size);

			if(field_size == 2 && pattern.equals(field[0].trim())){
			result = ( result || match_value(field[1].trim()));
            }

            if(NULL != field){
            	delete []field;	
			}
        }
	delete []new_output;
	return result;
	}
