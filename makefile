default: output

output: main.o car.o bus.o truck.o list.o
	g++ -Wall -g main.o car.o bus.o truck.o list.o -o output

main.o: main.cpp list.h
	g++ -c main.cpp -o main.o
    
car.o: car.cpp car.h
	g++ -c car.cpp -o car.o
    
bus.o: bus.cpp bus.h
	g++ -c bus.cpp -o bus.o
    
truck.o: truck.cpp truck.h
	g++ -c truck.cpp -o truck.o
	

list.o: list.h list.cpp
	g++ -c list.cpp -o list.o

clean: 
	rm -f output main.o car.o bus.o truck.o list.o
