

control: main.o vector2D.o line2D.o 
	g++ --std=c++11 -o control main.o vector2D.o line2D.o  

main.o: main.cc vector2D.h line2D.h 
	g++ --std=c++11 -c main.cc

vector2D.o: vector2D.h
	g++ --std=c++11 -c vector2D.cc

line2D.o: line2D.h vector2D.h
	g++ --std=c++11 -c line2D.cc

clean:
	rm -rf main.o line2D.o vector2D.o control

