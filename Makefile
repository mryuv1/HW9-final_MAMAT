# Welcomre to Mamat, 044101
#
# This is the project's Makefile. It contains the instructions for compiling
# the projects C files, and then link the generated objects into an executable.
# This simple file will compile "main.c" to "main.o" and then link it (with C
# runtime library) to the executable "prog.exe".
#
# To compile, open the terminal in the folder that contains
# this file and run "make".
#
# To clean, open the terminal in the folder that contains
# this file and run "make clean".
#
# All eclipse projects in this machine are under /home/mamat/Documents/


CC     = g++
CFLAGS = -Wall -g
OBJS   = main.o string.o port.o field.o ip.o  strings.exe
CPPOBJS_STING = string.cpp main.cpp


all:strings.exe fields.exe

fields.exe: main.o string.o string.h field.o field.h ip.o ip.h port.o port.h
	$(CC) $(CFLAGS)  string.o main.o field.o ip.o port.o -o fields.exe

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


clean:
	rm -fr *.exe $(OBJS)


