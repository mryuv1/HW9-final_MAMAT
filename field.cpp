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
	//	cout<<"HERE ######## - FIELD - SET VALUE____IP"<<endl;
		return ((Ip*)this)->set_value(val);
	}else if (type == PORT){
		return ((Port*)this)->set_value(val);
	}

	return false;
}
 bool Field::match_value(String val) const{
 	//cout<<"HERE &&&&&&&&&&&&&&&&"<<endl;
 	if(type == IP){
		return ((Ip*)this)->match_value(val);
	}else if (type == PORT){
		//cout<<"HERE 777777777777777"<<endl;
		return ((Port*)this)->match_value(val);
	}

	return false;
 }

 bool Field::match(String packet){
 	//cout<<"HERE 333333333333"<<endl;

 	
	String *NEWoutput;
	size_t size = 0;

	
	packet.split(",", &NEWoutput, &size);

	/*if (size != 4){
		delete []output;
		return false;
	}*/
	//cout<<"---$$$$$$$$$$$--------------size is ------------"<< size <<endl;
	
	
	bool result = false;
	String *ip;
			
		for(unsigned int i = 0; i < size ; i++){
			size_t ipSize = 0;
	//		cout<<"HERE 7777777777777"<<" i is :"<<i<<endl;
			NEWoutput[i].split("=", &ip, &ipSize);

			if(ipSize == 2 && pattern.equals(ip[0].trim())){
			result = ( result || match_value(ip[1].trim()));
			//cout<<"HERE 444444444444444"<<endl;
	//		cout<<"HERE 55555555555555555"<<endl;
            }

            if(NULL != ip){
            	delete []ip;
				
			}
        }
	
	//cout<<"HERE END MATCH -- result is "<<result<<endl;
	delete []NEWoutput;
	
	return result;

	}