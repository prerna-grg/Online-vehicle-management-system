#include <iostream>
#include <fstream>
#include <istream>
#include <cstdio>
#include <stdlib.h>
#include "bus.h"
#include "truck.h"
#include "car.h"
#include "list.h"
#include "list.cpp"
#define WmSize 30

using namespace std ;

int main(){

    ifstream fcar("car.txt");
    string s1 , s2 ;
	int n1 , n2 , n3 ;
	/*             CREATING CAR LINKED LIST            */
	Linkedlist<Car> CarLinkedList ;
	Car C;
   	while (fcar >> s1 >> s2 >> n1 >> n2 >> n3 ){
   		C.setData(s1,s2,n1,n2,n3);
		CarLinkedList.add(C);
   	}
   	fcar.close();

   	/*            CREATING BUS LINKED LIST             */
   	ifstream fbus("bus.txt");
	int n4 ;
	Linkedlist<Bus> BusLinkedList ;
	Bus B;
   	while (fbus >> s1 >> s2 >> n1 >> n2 >> n3 >> n4 ){
   		B.setData(s1,s2,n1,n2,n3,n4);
		BusLinkedList.add(B);
   	}
   	fbus.close();

   	/*           CREATING TRUCK LINKED LIST            */
   	ifstream ftruck("truck.txt");
	int n5 ;
	Linkedlist<Truck> TruckLinkedList ;
	Truck T ;
   	while (ftruck >> s1 >> s2 >> n1 >> n2 >> n3 >> n4 >> n5 ){
   		T.setData(s1,s2,n1,n2,n3,n4,n5);
		TruckLinkedList.add(T);
   	}
   	ftruck.close();
   	
   	/* PROGRAM EXECUTION */
	int n ;
	char use = 'y' ;
	while(use=='y'){
		cout << "enter 1 for adding vehicle" << endl ;
		cout << "enter 2 for removing vehicle" << endl ;
		cout << "enter 3 for watermelon transport" << endl ;
		cout << "enter 4 for car/bus/truck .. booking/unbooking" << endl ;
		cout << "enter 5 for finding number of vehicles required to accomodate people" << endl ;
		cout << "enter 6 for printing vehicle deatils" << endl ;
		cout << "enter 7 to find a car of your desired preferences" << endl ;
		cout << "enter 8 to exit program" << endl ;
		cin >> n ;
		while(cin.fail()){
			cout << "PLease enter integer input" << endl;
			cin.clear();
			cin.ignore(256,'\n');
			cin >> n ;
		}
		switch(n){
			/*==========================   ADD FUNCTION ====================*/
			case 1 : 
			{
				system("clear");
				int ad ;
				cout << "enter 1 for adding car" << endl ;
				cout << "enter 2 for adding bus" << endl ;
				cout << "enter 3 for adding truck" << endl ;
				cin >> ad ;
				while(cin.fail()){
					cout << "PLease enter integer input" << endl;
					cin.clear();
					cin.ignore(256,'\n');
					cin >> ad ;
				}
				switch(ad){
					case 1:
					{
						char addcar = 'y' ;
						while(addcar=='y'){
							cout << "\nenter details : " << endl ;
							cout << "Please enter the data one by one just the way we ask" << endl;
							cout << "name: " ;
							cin >> s1 ;
							// CHECK IF THE CAR WITH ENTERED NAME ALREADY EXISTS
							if(CarLinkedList.check(s1)){
								cout << "ERROR : This car is already present in the records " << endl ;
								goto jump ;
							}
							cout << "color: ";
							cin >> s2 ;
							cout << "mileage: " ;
							cin >> n1 ;
							while(cin.fail()){
								cout << "PLease enter integer input" << endl;
								cin.clear();
								cin.ignore(256,'\n');
								cin >> n1 ;
							}
							cout << "topSpeed: " ;
							cin >> n2 ;
							while(cin.fail()){
								cout << "PLease enter integer input" << endl;
								cin.clear();
								cin.ignore(256,'\n');
								cin >> n2 ;
							}
							cout << "numberOfGears: " ;
							cin >> n3 ;
							while(cin.fail()){
								cout << "PLease enter integer input" << endl;
								cin.clear();
								cin.ignore(256,'\n');
								cin >> n3;
							}
							C.setData(s1,s2,n1,n2,n3);
							CarLinkedList.add(C);
							cout << "\nSuccessfully Added !" << endl ;
							jump :
								cout << "\nwould you like to add more cars? y/n " ;
								cin >> addcar ;
						}
						break ;
					}
					case 2:
					{
						char addbus = 'y' ;
						while(addbus=='y'){
							cout << "\nenter details : " << endl ;
							cout << "Please enter the data one by one just the way we ask" << endl;
							cout << "name: " ;
							cin >> s1 ;
							// CHECK IF THE BUS WITH ENTERED NAME ALREADY EXISTS
							if(BusLinkedList.check(s1)){
								cout << "ERROR : This bus is already present in the records " << endl ;
								goto jumpb ;
							}
							cout << "color: ";
							cin >> s2 ;
							cout << "mileage: " ;
							cin >> n1 ;
							while(cin.fail()){
								cout << "PLease enter integer input" << endl;
								cin.clear();
								cin.ignore(256,'\n');
								cin >> n1 ;
							}
							cout << "topSpeed: " ;
							cin >> n2 ;
							while(cin.fail()){
								cout << "PLease enter integer input" << endl;
								cin.clear();
								cin.ignore(256,'\n');
								cin >> n2;
							}
							cout << "number of Gears: " ;
							cin >> n3 ;
							while(cin.fail()){
								cout << "PLease enter integer input" << endl;
								cin.clear();
								cin.ignore(256,'\n');
								cin >> n3 ;
							}
							cout << "number of Seats: " ;
							cin >> n4 ;
							while(cin.fail()){
								cout << "PLease enter integer input" << endl;
								cin.clear();
								cin.ignore(256,'\n');
								cin >> n4 ;
							}
							B.setData(s1,s2,n1,n2,n3,n4);
							BusLinkedList.add(B);
							cout << "\nSuccessfully Added !" << endl ;
							jumpb :
								cout << "\nwould you like to add more buses? y/n " ;
								cin >> addbus ;
						}
						break ;
					}
					
					case 3:
					{
						char addtruck = 'y' ;
						while(addtruck=='y'){
							cout << "\nenter details : " << endl ;
							cout << "Please enter the data one by one just the way we ask" << endl;
							cout << "name: " ;
							cin >> s1 ;
							// CHECK IF THE TRUCK WITH ENTERED NAME ALREADY EXISTS
							if(TruckLinkedList.check(s1)){
								cout << "ERROR : This truck is already present in the records " << endl ;
								goto jumpt ;
							}
							cout << "color: ";
							cin >> s2 ;
							cout << "mileage: " ;
							cin >> n1 ;
							while(cin.fail()){
								cout << "PLease enter integer input" << endl;
								cin.clear();
								cin.ignore(256,'\n');
								cin >> n1 ;
							}
							cout << "topSpeed: " ;
							cin >> n2 ;
							while(cin.fail()){
								cout << "PLease enter integer input" << endl;
								cin.clear();
								cin.ignore(256,'\n');
								cin >> n2 ;
							}
							cout << "number of Gears: " ;
							cin >> n3 ;
							while(cin.fail()){
								cout << "PLease enter integer input" << endl;
								cin.clear();
								cin.ignore(256,'\n');
								cin >> n3 ;
							}
							cout << "loading capacity in weight(kg): " ;
							cin >> n4 ;
							while(cin.fail()){
								cout << "PLease enter integer input" << endl;
								cin.clear();
								cin.ignore(256,'\n');
								cin >> n4 ;
							}
							cout << "loading capacity in volume(litre): " ;
							cin >> n5 ;
							while(cin.fail()){
								cout << "PLease enter integer input" << endl;
								cin.clear();
								cin.ignore(256,'\n');
								cin >> n5 ;
							}
							T.setData(s1,s2,n1,n2,n3,n4,n5);
							TruckLinkedList.add(T);
							cout << "\nSuccessfully Added !" << endl ;
							jumpt :
								cout << "\nwould you like to add more trucks? y/n " ;
								cin >> addtruck ;
						}
						break ;
					}
					default:
						break;
				}
				break ;
			}
			/*==========================   REMOVE FUNCTION ====================*/
			case 2 :
			{
				system("clear");
				char rem;
				rem = 'y' ;
				int temp_c=0 , temp_b=0 , temp_t=0 ;
				while(rem=='y'){
					int rm ;
					cout << "enter 1 for removing car" << endl ;
					cout << "enter 2 for removing bus" << endl ;
					cout << "enter 3 for removing truck" << endl ;
					cin >> rm ;
					while(cin.fail()){
						cout << "PLease enter integer input" << endl;
						cin.clear();
						cin.ignore(256,'\n');
						cin >> rm ;
					}
					//REMOVES THE VEHICLE .. IF VEHICLE IS NOT PRESENT IN RECORDS .. DISPLAYS ERROR
					switch(rm){
						case 1:
						{
							cout << "Please enter the name of the car you want to remove" << endl ;
							cout << "name: " ;
							cin >> s1 ;
							CarLinkedList.remove(s1); 
							break ;
						}
						case 2:
						{
							cout << "Please enter the name of the car you want to remove" << endl ;
							cout << "name: " ;
							cin >> s1 ;
							BusLinkedList.remove(s1);
							break ;
						}
						case 3:
						{	cout << "Please enter the name of the car you want to remove" << endl ;
							cout << "name: " ;
							cin >> s1 ;
							TruckLinkedList.remove(s1);
							break ;
						}
						default:
							break;
										
					}
					cout << "\nwould you like to remove any more vehicles? y/n  " ;
					cin >> rem ;
				}				
				break ;
			}
			/*==========================   WATERMELON TRANSPORT FUNCTION ====================*/
			case 3 :
			{
				system("clear");
				int wm ;
				cout << "please enter the number of watermelons you need to transport: " ;
				cin >> wm ;
				while(cin.fail()){
					cout << "PLease enter integer input" << endl;
					cin.clear();
					cin.ignore(256,'\n');
					cin >> wm ;
				}
				if(wm<=0){
					cout << "No trucks required" << endl;
					break;
				}
				wm = TruckLinkedList.transport(wm,WmSize);
				if(wm>0){
					cout<<"Sorry..No more trucks are available for the remaining "<<wm<<" watermelons" << endl;
				}
				break ;	
			}

			case 4 :
			/*==========================   BOOKING/UNBOOKING FUNCTION ====================*/
				{
				system("clear");
				int b_ub ;
				cout << "enter 1 for booking " << endl ;
				cout << "enter 2 for unbooking " << endl ;
				cin >> b_ub ;
				while(cin.fail()){
					cout << "PLease enter integer input" << endl;
					cin.clear();
					cin.ignore(256,'\n');
					cin >> b_ub ;
				}
				switch(b_ub){				
					case 1:
					{
						int book ;
						string name ;
						cout << "enter 1 to book a car" << endl ;
						cout << "enter 2 to book a bus" << endl ;
						cout << "enter 3 to book a truck" << endl ;
						cin >> book ;
						while(cin.fail()){
							cout << "PLease enter integer input" << endl;
							cin.clear();
							cin.ignore(256,'\n');
							cin >> book ;
						}
						switch(book){
							case 1:
								cout << "Following is the list of available cars :" << endl ;
								if (!CarLinkedList.printbook(b_ub)){
									cout << "Sorry No cars are available for booking" << endl;
									break ;
								}
								cout << "Please enter the name of car you wish to book: " ;
								cin >> name ;
								CarLinkedList.change_status(b_ub ,name);
								break ;
							case 2:
								cout << "Following is the list of available buses :" << endl ;
								if (!BusLinkedList.printbook(b_ub)){
									cout << "Sorry No buses are available for booking" << endl;
									break ;
								}
								cout << "Please enter the name of bus you wish to book: " ;
								cin >> name ;
								BusLinkedList.change_status(b_ub , name);
								break ;
							case 3:
								cout << "Following is the list of available trucks :" << endl ;
								if (!TruckLinkedList.printbook(b_ub)){
									cout << "Sorry No trucks are available for booking" << endl;
									break ;
								}
								cout << "Please enter the name of truck you wish to book: " ;
								cin >> name ;
								TruckLinkedList.change_status( b_ub , name);
								break ;
							default:
								break;
						}
					break ;
					}
					case 2:
					{
						int book ;
						string name ;
						cout << "enter 1 to unbook a car" << endl ;
						cout << "enter 2 to unbook a bus" << endl ;
						cout << "enter 3 to unbook a truck" << endl ;
						cin >> book ;
						while(cin.fail()){
							cout << "PLease enter integer input" << endl;
							cin.clear();
							cin.ignore(256,'\n');
							cin >> book ;
						}
						switch(book){
							case 1:
								cout << "Following is the list of booked cars :" << endl ;
								if (!CarLinkedList.printbook(b_ub)){
									cout << "Sorry No cars have been booked yet" << endl;
									break ;
								}
								cout << "Please enter the name of car you wish to unbook: " ;
								cin >> name ;
								CarLinkedList.change_status(b_ub ,name);
								break ;
							case 2:
								cout << "Following is the list of booked buses :" << endl ;
								if (!BusLinkedList.printbook(b_ub)){
									cout << "Sorry No buses have been booked yet" << endl;
									break ;
								}
								cout << "Please enter the name of bus you wish to unbook: " ;
								cin >> name ;
								BusLinkedList.change_status(b_ub ,name);
								break ;
							case 3:
								cout << "Following is the list of booked trucks :" << endl ;
								if (!TruckLinkedList.printbook(b_ub)){
									cout << "Sorry No trucks have been booked yet" << endl;
									break ;
								}
								cout << "Please enter the name of truck you wish to unbook: " ;
								cin >> name ;
								TruckLinkedList.change_status(b_ub ,name);
								break ;
							default:
								break;
							}
						break;
					}			
					default:
						cout << "please enter only the above mentioned numbers" << endl ;
						break ;
				}
				break ;
			}

			/*==========================   TRAVEL INQUIRY FUNCTION ====================*/
			case 5 :
				{
				system("clear");
				int p;
				cout << "Enter the number of people: " << endl ;
				cin>>p;
				while(cin.fail()){
					cout << "PLease enter integer input" << endl;
					cin.clear();
					cin.ignore(256,'\n');
					cin >> p ;
				}
				if(p<=0){
					cout << "No vehicles required" << endl ;
					break;
				}
				if(p>5) p = BusLinkedList.travel(p);
				if(p) p = CarLinkedList.carTravel(p);
				if(p)cout << "Sorry..No more vehicles are available for the remaining " << p << " people" << endl;
				break;
				}

			/*==========================   PRINT DETAIL FUNCTION ====================*/
			case 6 :
				{
				system("clear");
				string vehicle ;
				cout << "please enter the name of the vehicle: " ;
				cin >> vehicle ;
				if(!CarLinkedList.printData(vehicle)){
					if(!TruckLinkedList.printData(vehicle)){
						if(!BusLinkedList.printData(vehicle)){
							cout << "Sorry..No vehicle named "<< vehicle << " is registered in the records." << endl ;
						}
					}
				}
				break ;
				}

			/*========================== PREFERRED CAR DETAIL FUNCTION ====================*/
			case 7:
			{
				system("clear");
				string a ;
				int n1,n2;
				cout << "\nenter preferred color : " ;
				cin >> a ;
				cout << "enter minimum preferred mileage: ";
				cin >> n1 ;
				while(cin.fail()){
					cout << "PLease enter integer input" << endl;
					cin.clear();
					cin.ignore(256,'\n');
					cin >> n1 ;
				}
				cout << "enter minimum preferred top Speed: ";
				cin >> n2 ;
				while(cin.fail()){
					cout << "PLease enter integer input" << endl;
					cin.clear();
					cin.ignore(256,'\n');
					cin >> n2 ;
				}
				Car temp("temp" , a , n1 , n2 , 0);
				CarLinkedList.comp(temp);
				break;
			}
			case 8 :
				cout << "\nPROGRAM TERMINATED : THANK YOU FOR VISITING\n" << endl ;
				return 0 ;

			default :
				cout << "please enter any of the above mentioned numbers only!" << endl ;
				break ;
		
		}
		cout << "\nwould you like to continue? y/n  " ;
		cin >> use ;
	}
	cout << "\nPROGRAM TERMINATED : THANK YOU FOR VISITING\n" << endl ;
	return 0;
}
