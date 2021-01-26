
#include <iostream>
#include <stddef.h>
#include <cstring>
#include "string.h"
using namespace std;

String::String():data(NULL), length(0){
	//cout<<"HERE EMPTYYY"<<endl;
} //we need to check that;

String::String(const String &str){
	if (str.data == NULL){
		data = NULL;
		length = 0;
	}else{
	data = new char[str.length + 1];
	strcpy(data,str.data);
	length = str.length;
	//cout<<"HERE &&&&&&&&&str"<<endl;
	
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
	//cout<<"HERE *******************str"<<endl;
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
	//cout<<"old data in the string is________"<<rhs.data<<endl;
	//cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<rhs.data<<endl;
	strcpy(data,rhs.data);
	//cout<<"new data in the string is________"<<data<<endl;
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
	//	cout<<"NOT GOOD"<<endl;
		return;
	}

	//cout<<"HERE "<<endl;
	size_t numOfStrings = 1;
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
	
	 for(int j = 0; '\0' != tmp[j]; j++){
	 	for(int i = 0; '\0' != deli[i]; i++){
	 		if (deli[i] == tmp[j]){
	 			numOfStrings +=1;
	 		}
	 	}
	 }
	 
	 
	 //cout<<"tmp is------------------"<<tmp<<endl;
	// cout<<"numOfStrings is------------------"<<numOfStrings<<endl;
	 

	if (numOfStrings == 1){
		//cout<<"HERE ??????????????????????"<<endl;
		*output = new String[numOfStrings];
		(*output)[index] = String(tmp);
		*size = numOfStrings;
		//	cout<<"HERE 66666666666666666"<<endl;
		return;
	}

	if (output == NULL){
		//	cout<<"ONLY NUM OF STRINGS WITH OUT THW SPLIT"<<endl;
		*size = numOfStrings;
		return;
	}
	//cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;	
	*output = new String[numOfStrings];
	*size = numOfStrings;
	//cout<<"XXXXXXXXXXXXXXX"<<endl;

	if (output == NULL){
		//	cout<<"ONLY NUM OF STRINGS WITH OUT THW SPLIT"<<endl;
		*size = numOfStrings;
		return;
	}


	int startSplitFrom = 0;

	for(int i = 0; '\0' != deli[i]; i++){
		if(tmp[0] == deli[i]){
	//		cout<<"HERE EDITIONAL---------FIRST--------"<<endl;
			(*output)[index] =String();
			index = 1;
	 		startSplitFrom = 1;
		}
	}

	 for(int j = startSplitFrom; '\0' != tmp[j]; j++){
	 	for(int i = 0; '\0' != deli[i]; i++){
	 		if (deli[i] == tmp[j]){
	 			if (left != j){
	 //			cout<<"HERE NORMAL-----------------"<<endl;
	 			tmp[j] = '\0';
	 			(*output)[index] =String(&tmp[left]);
	 		}else{
	 //			cout<<"HERE BBBBBBBBBB"<<endl;
	 			(*output)[index] =NULL;
	 			 }
	 			left = j+1;
	 			index+=1; 			
	 		
	 //			cout<<"HERE NORMAL---------END--------"<<endl;

	 	
	 		}
	 	}
	}

	for(int i = 0; '\0' != deli[i]; i++){
		if(tmp[length-1] == deli[i]){
			(*output)[index] =NULL;
	// 		cout<<"HERE EDITIONAL---------END--------"<<endl;
		}else{
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
 	//	cout<<"what is the problem"<<endl;
 		return NULL;
 	}
 	char tmp[length+1];
	strcpy(tmp,data);
	int counterLeft = 0;
	int counterRight = (this->length);
	for (int i = 0; tmp[i] == ' '; i++){
		counterLeft+=1;
	}

	for (int i = length-1; tmp[i] == ' '; i--){
		counterRight-=1;
	}
	//cout<<"BEFORE THE TRIM TMP IS:  "<<tmp<<endl;
	tmp[counterRight] = '\0';
	//cout<<"After the trim:----------"<<tmp[counterLeft]<<" to-----------"<<tmp[counterRight-1]<<endl;
	return String(&tmp[counterLeft]);
 }



