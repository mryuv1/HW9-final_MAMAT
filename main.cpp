
#include <iostream>
#include <cstring>
#include<firewall>
#include<input>

using namespace std;
extern int check_args(int,char*);
extern void parse_input(Field&);

#if 1

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

	if(subMask[1].trim().equals(String("ip"))){
		Ip maskIp(subMask[2]);
		parse_input((Field&)maskIp);
	}else if(subMask[1].trim().equals(String("port"))){
		Port maskPort(subMask[2]);
		parse_input((Field&)maskPort);
	}

	delete []subMask;

    return 0;
}

#endif

#if 0
int main()
{
	if(0){
	String a("  yuval mayor    "), b(" 1   (   2   ) ,345, // 6789  , ,"), c("1993");
	String *d ;
	d = new String("1,  2 ,  4 ) fv ( rgfeerg ,18, 45");
	String *output;
	String *el;
	size_t size = 0;
	size_t godel = 0;

    String p;
    cout<<p.to_integer()<<endl;
	cout<<"seg 0"<<endl;

	b.split(",()/.", &output, &size);
	d->split(",()", &el, &godel);
	cout<<"seg 1"<<endl;
	cout<<(c.equals("1993"))<<endl;
	cout<<"size of output is:"<<size<<endl;
	cout<<"size of gosel is:"<<godel<<endl;

	for(size_t i=0; i<size; i++){
		cout<<"b loop:  "<<output[i].trim().to_integer()<<endl;
	}
	
	
	for(size_t i=0; i<godel; i++){
		el[i] = el[i].trim();
	}

	delete []output;
	delete []el;
	delete d;

	}

	//cout<<(output[3].to_integer())*2<<endl;

	String ip("IP");
	String port2("PORT");
	String compare1("40");
	String compare2("33.7.2.5");
	String valIp("33.250.4.5/8");
	String valIp2("33.250.4.5/16");
	String valPort("20-50");

	Port port1(port2);
	Ip ip1(ip);
	Ip ip2(ip);
	cout<<"before the sets"<<endl;
	port1.set_value(valPort);
	ip1.set_value(valIp);
	ip2.set_value(valIp2);
	cout<<"done with the sets"<<endl;
	bool statement1 = ip1.match_value(compare1);
	bool statement2 = port1.match_value(compare1);
	bool statement3 = ip1.match_value(compare2);
	bool statement4 = ip2.match_value(compare2);
	cout<<"match 111"<<endl;
	cout<<"should be false:"<<statement1<<endl;
	cout<<"should be true:" << statement2<< endl;
	cout<<"should be true:" << statement3<< endl;
	cout<<"should be false:" << statement4<< endl;

    return 0;
}
#endif 