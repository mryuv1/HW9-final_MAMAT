
#include <iostream>
#include <stddef.h>
#include <cstring>
#include "string.h"
using namespace std;

String::String():data(NULL), length(0){
	cout<<"empty"<<endl;
} //we need to check that;

String::String(const String &str){
	if (str.data == NULL){
		data = NULL;
		length = 0;
	}else{
	data = new char[str.length];
	strcpy(data,str.data);
	length = str.length;
	cout<<data<<endl;
	cout<<length<<endl;	
	}
	
}


String::String(const char *str){
	if (str == NULL){
		data = NULL;
		length = 0;
	}else{
	data = new char[strlen(str)];
	strcpy(data,str);
	length = strlen(this->data);
	cout<<data<<endl;
	cout<<length<<endl;
	}
}


String::~String(){
	if (NULL != this->data){
		delete[] data;
	}
}	

String& String::operator=(const String &rhs){
	if (NULL != this->data){
		delete[] data;
	}

    if (rhs.data == NULL){	
		data = NULL;
		length = 0;
	}else{
	this->data = new char[sizeof(rhs.data)+1];
	strcpy(data,rhs.data);
	this->length = sizeof(rhs.data)+1;
	}	

	return *this;
}


bool String::equals(const String &rhs) const{
	int x = strcmp(rhs.data,this->data);
	if (x == 0){
		return true;
	}
	return false;
}

bool String::equals(const char *rhs) const{
	int x = strcmp(rhs,this->data);
	if (x == 0){
		return true;
	}

	return false;
}

void String::split(const char *delimiters, String **output, size_t *size) const{
	if (this->data == NULL || delimiters == NULL || output == NULL){
		return;
	}
	char tmp[length];
	strcpy(tmp,data);
	int numOfStrings = 0;
	 for(int j = 0; '\n' != tmp[j]; j++){
	 	for(int i = 0; '\n' != delimiters[i]; i++){
	 		if (delimiters[i] == tmp[j]){
	 			numOfStrings +=1;
	 		}
	 	}
	 }

	if (numOfStrings != 0){
		*output = new String[numOfStrings];
	}
	
	int left = 0;
	int index = 0;
	 for(int j = 0; '\n' != tmp[j]; j++){
	 	for(int i = 0; '\n' != delimiters[i]; i++){
	 		if (delimiters[i] == tmp[j]){
	 			tmp[j] = '\n';
	 			(*output)[index] =String(&tmp[left]);
	 			left = j+1;
	 		}
	 	}
	}

	return;
}

int String::to_integer() const{
	return atoi(this->data);
}

 String String::trim() const{
 	if(data == NULL){
 		return String();
 	}
 	char tmp[length];
	strcpy(tmp,data);
	int counterLeft = 0;
	int counterRight = 0;
	for (int i = 0; tmp[i] == ' '; i++){
		counterLeft+=1;
	}

	for (int i = length; tmp[i] == ' '; i--){
		counterRight+=1;
	}

	tmp[counterRight] = '\n';
	return String(&tmp[counterLeft]);
 }



