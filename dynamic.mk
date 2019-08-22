code.out: code.o
	g++ code.o -lboost_log -lboost_filesystem -lboost_thread -pthread -o code.out

code.o: code.cc
	g++ -std=c++0x -Wall -DBOOST_ALL_DYN_LINK -I/usr/local/include -c code.cc

Clean:
	rm -f *.o
	rm -f *.out
