
#include <iostream>
#include <cstring>
#include "string.h"

using namespace std;

int main()
{
	String *a = new String("afdv");
	String *b = new String("abcdegf");
	String *c = new String("vfsbs     ");
	String *d = new String("vdger    ");
	String e("54227");
	String *f = new String("012");
	String g("abd, asr,dve,123");
	
	delete c;
	delete a;
	char *s = "abd\nfs";
	char *del = ",";
	String **here;
	size_t *her;
	char h[10];
	cout<<e.equals(e)<<endl;
	cout<<e.equals(e)<<endl;
	cout<<a->equals(e)<<endl;
	cout<<(c->to_integer()+1000)<<endl;
	strcpy(h,s);
	cout<<h<<endl;
	//g.split(del, here, her);


    return 0;
}