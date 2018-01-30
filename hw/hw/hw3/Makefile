proj3.exe: ColorClass.o ColorImageClass.o Pattern.o Main.o
	g++ ColorClass.o ColorImageClass.o Pattern.o Main.o -o proj3.exe

Main.o: Main.cpp
	g++ -c Main.cpp -o Main.o

ColorClass.o: ColorClass.cpp
	g++ -c ColorClass.cpp -o ColorClass.o

ColorImageClass.o: ColorImageClass.cpp
	g++ -c ColorImageClass.cpp -o ColorImageClass.o

Pattern.o: Pattern.cpp
	g++ -c Pattern.cpp -o Pattern.o

clean:
	rm -rf ColorClass.o ColorImageClass.o Pattern.o Main.o proj3.exe

