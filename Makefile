
# this is to allow emacs to compile easily
all: testq


testq: Makefile testq.cpp q.h
	g++ -g -o testq testq.cpp
	#./testq
	gdb testq
