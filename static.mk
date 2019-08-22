code.out: code.o
	g++ code.o -static -pthread -lboost_log -lboost_filesystem -lboost_thread -o code.out

code.o: code.cc
	g++ -Wall -std=c++0x -c code.cc

Clean:
	rm -f *.o
	rm -f *.out
