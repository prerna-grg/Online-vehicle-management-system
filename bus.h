#ifndef _bus_h
#define _bus_h

#include <iostream>
#include <fstream>
#include "car.h"

class Bus : public Car{

	private :
		int seats ;
	public :
		Bus();
		int checkSort(Car);
		Bus(string , string ,int , int, int , int);
		int checkSort(Bus);
		void setData(string , string , int , int , int , int);
		void printData();
		
	template <class Y> friend class Linkedlist ;
};

#endif
