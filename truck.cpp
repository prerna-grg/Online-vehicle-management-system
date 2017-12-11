#include <iostream>
#include "truck.h"
using namespace std;

// CONSTRUCTOR WITH NO ARGUMENT i.e. DEFAULT CONSTRUCTOR
Truck::Truck(){	
	name = "";
	color = "";
	mileage = 0 ;
	topSpeed = 0;
	numberOfGears = 0 ;
	kgLoad=0 ;
	litreLoad = 0;
	book_status = 0;
}

// GENERAL CONSTRUCTOR
Truck::Truck(string s1 , string s2 , int n1 , int n2 , int n3, int n4 , int n5){
	name = s1 ;
	color = s2 ;
	mileage = n1 ;
	topSpeed = n2 ;
	numberOfGears = n3 ;
	kgLoad = n4 ;
	litreLoad = n5 ;
}

// THIS FUNCTION WILL SET DATA IN ANY OBJECT IRRESOECTIVE OF THE CONSTRUCTOR USED
void Truck::setData(string s1 , string s2 , int i1 , int i2 , int i3 , int i4 , int i5){
	name = s1 ;
	color = s2 ;
	mileage = i1 ;
	topSpeed = i2 ;
	numberOfGears = i3 ;
	kgLoad = i4 ;
	litreLoad = i5 ;
}

// PRINTS THE DATA IN THE CONSOLE 
void Truck::printData(){
	cout << "Name: " << name << endl;
	cout << "Color: " << color << endl;
	cout << "Mileage: " << mileage << endl;
	cout << "Top Speed: " << topSpeed << endl;
	cout << "Number of gears: " << numberOfGears << endl;
	cout << "kgLoad: " << kgLoad << endl ;
	cout << "Liter Load: " << litreLoad << endl;
}

// CHECKS WHETHER THE INPUT TRUCK HAS GREATER CAPACITY OF LITRELOAD THAN THE ONE THAT IS BEING CHECKED
int Truck::checkSort(Truck T){
	if( (litreLoad-T.litreLoad)>=0 )return 1 ;
	else return 0 ;
}

