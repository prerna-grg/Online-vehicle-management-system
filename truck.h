#ifndef _truck_h
#define _truck_h

#include <iostream>
#include <fstream>
#include "car.h"

class Truck : public Car{

	private:
		int kgLoad ;
		int litreLoad ;
	public:
		Truck();
		Truck(string , string ,int , int, int , int , int);
		int checkSort(Truck);
		void setData(string , string , int , int , int , int , int );
		void printData();
		
	template <class Y> friend class Linkedlist ;
};

#endif
