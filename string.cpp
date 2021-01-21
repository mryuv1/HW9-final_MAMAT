
#include <iostream>
#include <stddef.h>
#include <cstring>
#include "string.h"
using namespace std;

String::String():data(NULL), length(0){
	cout<<"empty String"<<endl;
} //we need to check that;

String::String(const String &str){
	if (str.data == NULL){
		data = NULL;
		length = 0;
	}else{
	data = new char[str.length];
	strcpy(data,str.data);
	length = str.length;
	cout<<data<<" length:"<< length << " ," << "new String" <<endl;
	}
	
}


String::String(const char *str){
	if (str == NULL || strlen(str) == 0){
		data = NULL;
		length = 0;
		cout<<"empty2"<<endl;
	}else{
	data = new char[strlen(str)];
	strcpy(data,str);
	length = strlen(this->data);
	cout<<data<<" length:"<< length << " ," << "new String" <<endl;
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
	size_t numOfStrings = 1;
	 for(int j = 0; '\0' != tmp[j]; j++){
	 	for(int i = 0; '\0' != delimiters[i]; i++){
	 		if (delimiters[i] == tmp[j]){
	 			numOfStrings +=1;
	 		}
	 	}
	 }

	 *size = numOfStrings;
	 
	if (numOfStrings != 0){
		*output = new String[numOfStrings];
	}
	cout<<numOfStrings<<endl;
	int left = 0;
	int index = 0;
	 for(int j = 0; '\0' != tmp[j]; j++){
	 	for(int i = 0; '\0' != delimiters[i]; i++){
	 		if (delimiters[i] == tmp[j]){
	 			tmp[j] = '\0';
	 			(*output)[index] =String(&tmp[left]);
	 			left = j+1;
	 			index+=1;
	 			cout<<length<<endl;

	 		}else if ('\0' == tmp[j+1]){
	 			(*output)[index] =String(&tmp[left]);
	 			return;
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

	tmp[counterRight] = '\0';
	return String(&tmp[counterLeft]);
 }



