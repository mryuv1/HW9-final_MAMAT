CC=gcc
CFLAGS= -g -Wall -std=c99 -c -fpic 
CLINK=$(CC)

CC     = g++
CFLAGS = -Wall -g 
CPPLIBS = -fpic -shared
CLIBS = -shared  -o  firewall.so -L.
RM = rm -rf *.o *.exe 
CPPS = ip.cpp field.cpp port.cpp string.cpp
OBJ = ip.o field.o port.o string.o
LIBS = firewall.so libinput.so




all:strings.exe fields.exe firewall.exe

firewall.exe: main.o string.o string.h field.o field ip.o ip.h port.o port.h
	$(CC) $(CFLAGS)  string.o main.o field.o ip.o port.o libinput.so -o firewall.exe

strings.exe: main.o string.o string.h
	$(CC) $(CFLAGS)  string.o main.o -o strings.exe

main.o: main.cpp string.h port.h ip.h field.h
	$(CC) $(CFLAGS) -c  main.cpp

port.o: string.o port.h port.cpp
	$(CC) $(CFLAGS) -c  port.cpp

ip.o: string.o ip.h ip.cpp
	$(CC) $(CFLAGS) -c  ip.cpp

field.o: string.o field.h
	$(CC) $(CFLAGS) -c  field.cpp

string.o: string.cpp string.h
	$(CC) $(CFLAGS) -c  string.cpp





#firewall.exe: $(LIBS)
#	$(CC) $(CFLAGS) $(LIBS) -o firewall.exe -L.

#firewall.so: $(OBJ)
#	$(CLINK) $(OBJ) $(CLIBS) 


#$(OBJ): $(CPPS)
#	$(CC) $(CFLAGS) -c  $(CPPS)

clean:
	$(RM) 