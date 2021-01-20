#include <stddef.h>
#include <iostream>
#include "String.h"


String::String():data(NULL), length(0){} //we need to check that;

String::String(const String &str){
	if (str->data == NULL){
		data = NULL;
		length = 0;
	}else{
	data = new char[sizeof(str->data)+1];
	strcpy(data,str->data);
	length = str.length;	
	}
	
}


String::String(const char *str){
	if (str->data == NULL){
		data = NULL;
		length = 0;
	}else{
	data = new char[sizeof(str)+1];
	strcpy(data,str);
	length = sizeof(str)+1;
	}
}


String::~String(const char *str){
	if (NULL != this->data){
		delete[] data;
	}
}	

String& String::operator=(const String &rhs){
	if (NULL != this->data){
		~Strings(this->data);
	}

    if (rhs->data == NULL){	
		data = NULL;
		length = 0;
	}else{
	this->data = new char[sizeof(rhs->data)+1];
	strcpy(data,rhs->data);
	this.length = sizeof(rhs->data)+1;
	}	

	return *this;
}


bool String::equals(const String &rhs){
	int x = strcmp(rhs->data,this->data);
	if (x == 0){
		return TRUE;
	}
	return FALSE;
}

bool String::equals(const char *rhs){
	int x = strcmp(rhs,this->data);
	if (x == 0){
		return TRUE;
	}

	return FALSE;
}

void String::split(const char *delimiters, String **output, size_t *size) const{
	if (this->data == NULL || delimiters = NULL || output == NULL){
		return;
	}

	int numOfStrings = 0
	 for(j = 0; '\n' != this->data[j]; j++){
	 	for(i = 0; '\n' != delimiters[i]; i++){
	 		if (delimiters[i] == data[j]){
	 			counter +=1;
	 		}
	 	}
	 }

	if (counter != 0){
		String *list = new String[counter];
	}
	int right = 0;
	int left = 0;
	int index = 0;
	 for(j = 0; '\n' != this->data[j]; j++){
	 	for(i = 0; '\n' != delimiters[i]; i++){
	 		if (delimiters[i] == data[j]){
	 			this->data[j] = '\n'
	 			list[index] = String(data[left]);
	 			left = j+1;
	 		}
	 	}
	}
}

int String::to_integer() const{
	return atoi(this->data);
}

 String trim() const{
 	if(data = NULL){
 		return;
 	}
 	char tmp[length];
	strcpy(tmp,data);
	int counterLeft = 0;
	int counterRight = 0;
	for (i = 0; tmp[i] == ''; i++){
		counterLeft+=1;
	}

	for (i = length; tmp[i] == ''; i--){
		counterRight+=1;
	}

	tmp[counterRight] = '\n';
	return String(tmp[counterLeft]);
 }



