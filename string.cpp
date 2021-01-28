
#include <iostream>
#include <stddef.h>
#include <cstring>
#include "string.h"
using namespace std;

String::String():data(NULL), length(0){} 

String::String(const String &str){
	if (str.data == NULL){
		data = NULL;
		length = 0;
	}else{
	data = new char[str.length + 1];
	strcpy(data,str.data);
	length = str.length;	
	}
	
}


String::String(const char *str){
	if (str == NULL || strlen(str) == 0){
		data = NULL;
		length = 0;
	}else{
	data = new char[strlen(str) + 1];
	strcpy(data,str);
	length = strlen(this->data);
	}
}


String::~String(){
	if (NULL != data){
		delete[] data;
	}
}	

String& String::operator=(const String &rhs){
	if (NULL != this->data){
		delete[] data;
	}
    if (rhs.data == NULL){	
		return *this;
	}else{
	this->data = new char[strlen(rhs.data) + 1];
	strcpy(data,rhs.data);
	this->length = strlen(rhs.data);
	}	

	return *this;
}

String& String::operator=(const char *str){
	if (NULL != this->data){
		delete[] data;
	}

    if (str == NULL){	
		data = NULL;
		length = 0;
	}else{
	this->data = new char[strlen(str) + 1];
	strcpy(data,str);
	this->length = strlen(str);
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
	if (delimiters == NULL || size == NULL){
		return;
	}
	size_t num_of_strings = 1;
	int left = 0;
	int index = 0;
	char deli[strlen(delimiters)+1];
	strcpy(deli,delimiters);

	if(this->data == NULL){
		*size = 0;
		*output = NULL;
		return;
	}
	char tmp[length + 1];
	strcpy(tmp,data);

	/* count numbers of sub strings*/
	 for(int j = 0; '\0' != tmp[j]; j++){
	 	for(int i = 0; '\0' != deli[i]; i++){
	 		if (deli[i] == tmp[j]){
	 			num_of_strings +=1;
	 		}
	 	}
	 }

	 /* IF OUTPUT IS null go back with num of sub Strings*/
	 if (output == NULL){
		*size = num_of_strings;
		return;
	}	


	if (num_of_strings == 1){
		*output = new String[num_of_strings];
		(*output)[index] = String(tmp);
		*size = num_of_strings;
		return;
	}

	
	*output = new String[num_of_strings];
	*size = num_of_strings;
	if (output == NULL){
		*size = num_of_strings;
		return;
	}


	int startSplitFrom = 0;
	/* special case if the input STARTS
	 with 2 delimeters one after one*/
	for(int i = 0; '\0' != deli[i]; i++){
		if(tmp[0] == deli[i]){
			(*output)[index] =String();
			index = 1;
	 		startSplitFrom = 1;
		}
	}

	 for(int j = startSplitFrom; '\0' != tmp[j]; j++){
	 	for(int i = 0; '\0' != deli[i]; i++){
	 		if (deli[i] == tmp[j]){
	 			if (left != j){
	 			tmp[j] = '\0';
	 			(*output)[index] =String(&tmp[left]);
	 		}
	 		else{
	 			(*output)[index] =NULL;
	 			 }
	 			left = j+1;
	 			index+=1; 	
	 		}
	 	}
	}

	/* special case if the input ENDS
	 with 2 delimeters one after one*/
	for(int i = 0; '\0' != deli[i]; i++){
		if(tmp[length-1] == deli[i]){
			(*output)[index] =NULL;
		}
		else{
			(*output)[index] =String(&tmp[left]);
		}
	}

	return;
}

int String::to_integer() const{
	if(data == NULL){
 		return 0;
 	}
	return atoi(this->data);
}

 String String::trim() const{
 	if(data == NULL){
 		return NULL;
 	}
 	char tmp[length+1];
	strcpy(tmp,data);
	int counter_left = 0;
	int counter_right = (this->length);
	for (int i = 0; tmp[i] == ' '; i++){
		counter_left+=1;
	}

	for (int i = length-1; tmp[i] == ' '; i--){
		counter_right-=1;
	}
	tmp[counter_right] = '\0';
	return String(&tmp[counter_left]);
 }



