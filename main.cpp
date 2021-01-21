
#include <iostream>
#include <cstring>
#include "string.h"
#include "port.h"
#include "ip.h"
using namespace std;

//debug only for strings
#if 0
int main()
{
	String a("  yuval mayor    "), b(" amir, gildor,,,  mai, yael,yarden, 32     "), c("1993");
	String *d;
	String *output;
	d = output;
	size_t size = 0;

	b.split(",,", &output, &size);
	
	cout<<(c.equals("1993"))<<endl;
		cout<<size<<endl;

	String g = output[0].trim();	


	//cout<<(output[3].to_integer())*2<<endl;
	char test[] = "hi there";
	cout<<test<<endl;

    return 0;
}

#endif 

int main()
{
	
	String ip("src-ip=3.3.3.3");
	String port2("port=40");

	String compare("40");
	String valIp("122.5.4.5/8");
	String valPort("20-50");

	Port port1(port2);
	
	Ip ip1(ip);
	cout<<"before the sets"<<endl;
	port1.set_value(valPort);
	cout<<"done with the port"<<endl;
	ip1.set_value(valIp);
	cout<<"done with the ip"<<endl;
	bool statement1 = ip1.match_value(compare);
	bool statement2 = port1.match_value(compare);
	cout<<"match 111"<<endl;
	cout<<"should be false:"<<statement1<<endl;
	cout<<"should be true:" << statement2<< endl;


    return 0;
}