CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec.cpp llrec-test.cpp
	g++ -g -Wall llrec.cpp llrec-test.cpp -o llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------


clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 