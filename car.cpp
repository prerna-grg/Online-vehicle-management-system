#include <iostream>
#include "car.h"
using namespace std;

// CONSTRUCTOR WITH NO ARGUMENT i.e. DEFAULT CONSTRUCTOR
Car::Car(){
	name = "";
	color = "";
	mileage = 0 ;
	topSpeed = 0;
	numberOfGears = 0 ;
	book_status = 0;
}

// GENERAL CONSTRUCTOR
Car::Car(string s1 , string s2 , int n1 , int n2 , int n3){
	name = s1 ;
	color = s2 ;
	mileage = n1 ;
	topSpeed = n2 ;
	numberOfGears = n3 ;	
}

// THIS FUNCTION WILL SET DATA IN ANY OBJECT IRRESOECTIVE OF THE CONSTRUCTOR USED
void Car::setData(string s1 , string s2 , int i1 , int i2 , int i3){
	name = s1 ;
	color = s2 ;
	mileage = i1 ;
	topSpeed = i2 ;
	numberOfGears = i3 ;
}

// PRINTS THE DATA IN THE CONSOLE 
void Car::printData(){
	cout << "Name: " << name << endl;
	cout << "Color: " << color << endl;
	cout << "Mileage: " << mileage << endl;
	cout << "Top Speed: " << topSpeed << endl;
	cout << "Number of gears: " << numberOfGears << endl;
}

/* SINCE ALL CARS HAVE 5 SEATS THE FUNCTION RETURNS ZERO ... IN CASE CAR DATA CHANGES WE JUST NEED TO UPDATE THE FOLLOWING FUNCTION */
int Car::checkSort(Car B){
	return 0 ;
}

bool Car::operator >(Car C){
	
	if(mileage > C.mileage && topSpeed>C.topSpeed)return true;
	return false ;
}

bool Car::operator ==(Car C){
	
	if(color==C.color)return true;
	return false ;
}
