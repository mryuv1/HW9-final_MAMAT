#include <stddef.h>
#include <iostream>
#include "String.h"


String::String():data(new char[0]), length(0){} //we need to check that;

String::String(const String &str){
	this->data = new char[sizeof(str->data)+1];
	strcpy(data,str->data);
	this.length = str->length;
}


String::String(const char *str){
	this->data = new char[sizeof(str)+1];
	strcpy(data,str);
	this.length = sizeof(str)+1;
}


String::~String(const char *str){
	delete[] data;
}	

String& String::operator=(const String &rhs){     //maybe the syntax is wrong
	~Strings(this->data);
	this->data = new char[sizeof(rhs)+1];
	strcpy(data,rhs);
	this.length = sizeof(rhs)+1;
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

void String::split(const char *delimiters, String **output, size_t *size) const;