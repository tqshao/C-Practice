proj4a.exe: LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o project4a.o
	g++ LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o project4a.o -o proj4a.exe

project4a.o: project4a.cpp
	g++ -c project4a.cpp -o project4a.o

LinkedNodeClass.o: LinkedNodeClass.cpp
	g++ -c LinkedNodeClass.cpp -o LinkedNodeClass.o

SortedListClass.o: SortedListClass.cpp
	g++ -c SortedListClass.cpp -o SortedListClass.o

FIFOQueueClass.o: FIFOQueueClass.cpp
	g++ -c FIFOQueueClass.cpp -o FIFOQueueClass.o

LIFOStackClass.o: LIFOStackClass.cpp
	g++ -c LIFOStackClass.cpp -o LIFOStackClass.o

clean:
	rm -rf LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o project4a.o proj4a.exe

