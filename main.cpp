
#include <iostream>
#include <cstring>
#include "string.h"
#include "port.h"
#include "ip.h"

using namespace std;
extern int check_args(int,char*);
extern void parse_input(Field&);

#if 0

int main(int argc, char *argv[]){
	
	if (check_args(argc,*argv) != 0){
		cout<<"err_arg"<<endl;
		return 0;
	}

	String mask(argv[0]);
	char delimiters[] = "-=";
	String *subMask;
	size_t sizes;

	mask.split(delimiters, &subMask, &sizes);

	if(subMask[1].equals(String("ip"))){
		Ip maskIp(subMask[2]);
		parse_input((Field&)maskIp);
	}else if(subMask[1].equals(String("port"))){
		Port maskPort(subMask[2]);
		parse_input((Field&)maskPort);
	}

	delete []subMask;

    return 0;
}

#endif

#if 1
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

	cout<<(output[7].trim().to_integer())*3<<endl;

	if(0){
	//cout<<(output[3].to_integer())*2<<endl;
	char test[] = "hi there";
	cout<<test<<endl;

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
	}

    return 0;
}
#endif 