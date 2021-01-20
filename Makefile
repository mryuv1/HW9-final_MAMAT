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
OBJS   = main.o string.o
CPPOBJS = string.cpp main.cpp



prog.exe: main.o string.o string.h
	$(CC) $(CFLAGS)  string.o main.o -o prog.exe

main.o: main.cpp string.h
	$(CC) $(CFLAGS) -c  main.cpp

string.o: string.cpp string.h
	$(CC) $(CFLAGS) -c  string.cpp

clean:
	rm -fr *.exe $(OBJS)


