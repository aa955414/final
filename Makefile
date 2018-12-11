#Final Makefile Alyssa Atkinson

all: 
	make build
	make doc
	make check

count: final.o 
	g++ -o count final.o

final.o: final.cc
	gcc -c final.cc

build: count

doc: 
	doxygen final.cc

check:
	valgrind ./count
	cppcheck count

clean:
	-rm *.o
	-rm count
	-rm -r html
	-rm -r latex
