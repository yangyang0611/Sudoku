all: generate transform solve
generate: generate.o
	g++ -o generate generate.o

generate.o: generate.cpp
	g++ -c generate.cpp

transform: transform.o
	g++ -o transform transform.o

transform.o: transform.cpp
	g++ -c transform.cpp

solve: solve.o
	g++ -o solve solve.o

solve.o: solve.cpp
	g++ -c solve.cpp

clean:
	rm solve*.o transform*.o generate*.o
