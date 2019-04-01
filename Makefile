#!make -f

demo: TreeDemo.o Tree.o
	g++ -std=c++11 $^ -o demo

test: TreeTest.o Tree.o
	g++ -std=c++11 $^ -o test

%.o: %.cpp Tree.hpp
	g++ -std=c++11 --compile $< -o $@

clean:
	rm -f *.o demo test
