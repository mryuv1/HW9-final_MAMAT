CC=gcc
CFLAGS= -g -Wall -std=c99 -c -fpic 
CLINK=$(CC)

CC     = g++
CFLAGS = -Wall -g -fpic -shared
CLIBS = -shared  -o  firewall.so -L.
RM = rm -rf *.o *.exe 
CPPS = ip.cpp field.cpp port.cpp string.cpp
OBJ = ip.o field.o port.o string.o
LIBS = firewall.so libinput.so

firewall.exe: $(LIBS)
	$(CC) $(CFLAGS) $(LIBS) -o firewall.exe -L.

firewall.so: $(OBJ)
	$(CLINK) $(OBJ) $(CLIBS) 


$(OBJ): $(CPPS)
	$(CC) $(CFLAGS) -c  $(CPPS)

clean:
	$(RM) 