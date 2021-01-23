
CFLAGS= -g -Wall  -c -fpic 
CLINK=$(CC)

CC     = g++

CPPLIBS = -fpic -shared
CLIBS = -shared  -o  firewall.so -L.
RM = rm -rf *.o *.exe 
CPPS = ip.cpp field.cpp port.cpp string.cpp 
OBJ = ip.o field.o port.o string.o
LIBS = firewall.so libinput.so




all: firewall.so firewall.exe  

#firewall.exe: main.o string.o string.h field.o ip.o ip.h port.o port.h
#	$(CC) $(CFLAGS)   main.o string.o field.o ip.o port.o  libinput.so -o firewall.exe

#strings.exe: main.o string.o string.h
#	$(CC) $(CFLAGS)  string.o main.o -o strings.exe

#main.o: main.cpp string.o port.o ip.o field.o 
#	$(CC) $(CFLAGS) -c  main.cpp

#port.o: string.o string.cpp port.cpp field.o
#	$(CC) $(CFLAGS) -c  port.cpp

#ip.o: string.o ip.h ip.cpp field.o
#	$(CC) $(CFLAGS) -c  ip.cpp

#field.o: string.cpp string.o field.h
#	$(CC) $(CFLAGS) -c  field.cpp

#string.o: string.cpp string.h
#	$(CC) $(CFLAGS) -c  string.cpp



firewall.so: $(OBJ)
	$(CLINK) $(OBJ) $(CLIBS) 

firewall.exe: $(LIBS) main.o
	$(CC) -g -Wall  main.o -o firewall.exe -Lfirewall.so -Llibinput.so

main.o: main.cpp
		$(CC) -g -Wall -c main.cpp


$(OBJ): $(CPPS)
	$(CC) $(CFLAGS) -c  $(CPPS)

clean:
	$(RM) 