#ifndef _car_h
#define _car_h

#include <iostream>
#include <fstream>

using namespace std ;

class Car{

	protected :
		string name ;
		string color ;
		int book_status ;
		int mileage ;
		int topSpeed ;
		int numberOfGears ;		
	public:
		virtual void printData();
		Car();
		Car(string , string ,int , int, int);
		void setData(string , string , int , int , int );
		int checkSort(Car);
		template <class Y> friend class Linkedlist ;
		bool operator >(Car);
		bool operator ==(Car);
		
};

#endif

