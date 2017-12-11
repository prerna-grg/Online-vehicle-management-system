#include <iostream>
#include <fstream>
#include "bus.h"
#include "list.h"
#include "truck.h"
#include "car.h"
#include <string>
#include <typeinfo>

//NODE DEFAULT CONSTRUCTOR
template <class T>
Node<T>::Node(){
	prev = NULL ;
	next = NULL ;
};

//NODE GENERIC CONSTRUCTOR
template <class T>
Node<T>::Node(T a){
	obj = a;
	next = NULL ;
	prev = NULL ;
};

//LINKEDLIST CONSTRUCTOR
template <class T>
Linkedlist<T>::Linkedlist(){
    head = NULL;
    tail = NULL;
}

//LINKEDLIST DESTRUCTOR
template <class T>
Linkedlist<T>::~Linkedlist(){

	while(head!=NULL){
		Node<T>*temp = head->next ;
		delete head ;
		head = temp ;
	}
}

//CHECKS IF THE LIST IS EMPTY
template <class T>
bool Linkedlist<T>::isempty(){
	if(head==NULL)return true;
	return false;
}

//ADD FUNCTION FOR NODES
template <class T>
void Linkedlist<T>::add(T a){

	// IF HEAD IS NULL , IT ADD THE FIRST ELEMENT 
	if(head==NULL){
		Node<T>*temp = new Node<T>(a);
		head = temp ;
		tail = head ;
		return ;
	}
	
	//FOR CARS IT ADD AT FRONT
	if(typeid(T)==typeid(Car)){
		Node<T>*temp = new Node<T>(a);
		head->prev = temp ;
		temp->next = head ;
		head = temp ;
		head->prev = NULL;
		return;
	}
	
	//FOR BUSES IT SORTS IN DECRESING ORDER OF SEATS
	//FOR TRUCKS IT SORTS IN DECREASING ORDER OF LITRELOAD
	else{
		Node<T>*addtemp = new Node<T>(a);
		Node<T>*temp = head ;
		if( addtemp->obj.checkSort(temp->obj)==1){
			head->prev = addtemp;
			addtemp->next = head ;
			head = addtemp ;
			return ;
		}
		while(temp->next!=NULL){
			if( addtemp->obj.checkSort(temp->next->obj)==1 ){
				addtemp->next = temp->next ;
				temp->next->prev = addtemp ;
				addtemp->prev = temp;
				temp->next = addtemp;
				return ;
			}
			else temp = temp->next ;
		}
		temp->next = addtemp ;
		addtemp->prev = temp ;
		addtemp->next = NULL;
		return ;
	}
}


//CHECKS IF VEHICLE NAMED s1 IS PRESENT IN THE LIST
template <class T>
const int Linkedlist<T>::check(const string s1){
	
	Node<T>*temp = head ;
	while( temp!=NULL ){
		if(temp->obj.name.compare(s1)==0) return 1 ;
		temp = temp->next ;
	}
	return 0 ;
}

//PRINTS VEHICLE DETAILS OF THE VEHICLE NAMED s1
template <class T>
int Linkedlist<T>::printData(const string s1){
	
	Node<T>*temp = head ;
	while(temp !=NULL){
		if(temp->obj.name.compare(s1)==0) {
			temp->obj.printData();
			return 1;
		}
		temp = temp->next ;
	}

	return 0 ;
}

//REMOVES NODE FROM THE LINKED LIST
template <class T>
void Linkedlist<T>::remove(const string s1){

	Node<T>*temp = head ;
	if(isempty()){
		cout << "LIST IS EMPTY" << endl;
		return ;
	}
	if( (temp->obj.name).compare(s1)==0 ){
		head = temp->next ;
		cout << "Successfully deleted" << endl ;
		return ;
	}
	temp = temp->next ;
	if(temp==NULL){
		cout << "member not found : please enter a valid name " << endl;
		return;
	}
	while(temp->next != NULL){
		if( (temp->obj.name).compare(s1)==0 ){
			temp->next->prev = temp->prev ;
			temp->prev->next = temp->next ;
			cout << "Successfully deleted" << endl ;
			return ;
		}
		temp = temp->next ;
	}
	if( (temp->obj.name).compare(s1)==0 ){
		cout << "Successfully deleted" << endl ;
		temp->prev->next = NULL ;
		tail=temp->prev;
		return ;
	}
	cout << "member not found : please enter a valid name " << endl;
	
	return ;	
}


//LISTS OUT THE MINIMUM NUMBER OF TRUCKS REQUIRED TO TRANSPORT THE GIVEN NUMBER OF WATERMELONS
template <class T>
const int Linkedlist<T>::transport(int wm , const int size){

	Node<T>*temp = head ;
	if(isempty()){
		cout << "LIST IS EMPTY" << endl;
		return wm;
	}
	int count=0;
	if(typeid(T)==typeid(Truck)){ 
		while( temp->next!=NULL){
			if( wm>=temp->next->obj.litreLoad/size ){
				cout << temp->obj.name << endl ;
				count++;
				wm = wm - temp->obj.litreLoad/size ;
				if(wm<=0){
					cout << "Your watermelons will be transported in above given " << count << " trucks" << endl;
					cout << "Please go into the booking section from the main menu to book your trucks" << endl;
					return 0;
				}
				else temp = temp->next ;
			}
			else temp = temp->next ;
		}
		cout << temp->obj.name << endl ;
		wm = wm-temp->obj.litreLoad/size ;
		if(wm<=0)wm=0;
		count++;
	}
	cout << "Your watermelons will be transported in above given " << count << " trucks" << endl;
	cout << "Please go into the booking section from the main menu to book your trucks" << endl;
	return wm;
}


//LISTS OUT THE MINIMUM NUMBER OF BUSES REQUIRED FOR ACCOMODATION OF GIVEN NUMBER OF PEOPLE
template <class T>
int Linkedlist<T>::travel(int p){

	int count=0;
	Node<T>*temp = head ;
	if(isempty()){
		cout << "LIST IS EMPTY" << endl;
		return p;
	}
	if(typeid(T)==typeid(Bus)){
		while( temp->next!=NULL){
			if( p>temp->next->obj.seats ){
				cout << temp->obj.name << endl ;
				count++;
				p = p - temp->obj.seats ;
				if(p<0)p=0;
				if(p<=5){
					cout << "Above given " << count << " buses are available for you ... Happy journey :)" << endl;
					cout << "Please go into the booking section from the main menu to book your buses" << endl;
					return p;
				}
				else temp = temp->next ;
			}
			else temp = temp->next ;
		}
		cout << temp->obj.name << endl;
		count++;
		p=p-temp->obj.seats ;
		if(p<0)p=0;
	}
	cout << "Above given " << count << " buses are available for you ... Happy journey :)" << endl; 
	cout << "Please go into the booking section from the main menu to book your buses" << endl;
	return p;
}

template <class T>
int Linkedlist<T>::carTravel(int p){

	int count=0 ;
	if(typeid(T)==typeid(Car)){	
		Node<T>*temp = head ;
		while(temp!=NULL){
			cout << temp->obj.name << endl ;
			count++;
			p = p-5;
			if(p<=0){
				cout << "Above given " << count << " cars are available for you ... Happy journey :)" << endl;	
				cout << "Please go into the booking section from the main menu to book your cars" << endl;			
				return 0;
			}
			temp= temp->next;
		}
		
		cout << "Above given " << count << " cars are available for you ... Happy journey :)" << endl;
		cout << "Please go into the booking section from the main menu to book your cars" << endl;
		return p;
	}		
}

//THIS FUNCTION WILL PRINT THE BOOKED/UNBOOKED VEHICLES FOR THE CUSTOMER TO CHOOSE FROM
template <class T>
const bool Linkedlist<T>::printbook(const int a){

	bool printed = false ;
	if(a==1){
		Node<T>*temp = head ;
		while(temp!=NULL){
			if(temp->obj.book_status == 0){
				cout << temp->obj.name << endl;
				printed = true ;
			}
			temp = temp->next ;
		}
	}
	if(a==2){
		Node<T>*temp = head ;
		while(temp!=NULL){
			if(temp->obj.book_status == 1 ){
				cout << temp->obj.name << endl;
				printed = true ;
			}
			temp = temp->next ;
		}
	}
	return printed ;
}

//CHANGES BOOKING STATUS AS PER USER INPUT
template <class T>
void Linkedlist<T>::change_status(const int a , const string s1){
	
	if(a==1){
		Node<T>*temp = head ;
		while(temp!=NULL){
			if( (temp->obj.name).compare(s1)==0 ){
				if( temp->obj.book_status == 1 )
					cout << "Sorry..This vehicle is already booked!" << endl ;
				else {
					temp->obj.book_status = 1;
					cout << "Your vehicle has been successfully booked!" << endl;
					cout << "HAPPY JOURNEY :)" << endl;
				}
				return ;
			}
			temp = temp->next ;
			
		}
	}
	if(a==2){
		Node<T>*temp = head ;
		while(temp!=NULL){
			if( (temp->obj.name).compare(s1)==0 ){
				if( temp->obj.book_status == 0 ) 
					cout << "Sorry..This vehicle is already not booked by any customer!" << endl ;
				else {
					temp->obj.book_status = 0;
					cout << "Your vehicle has been successfully unbooked!" << endl;
				}
				return ;
			}
			temp = temp->next ;
		}
	}	
	cout << "Sorry the name entered is invalid !" << endl ; 
	return ;
}

//FUNCTON GIVES BEST PREFERRED CAR AS PER THE USERS' CHOICE
template <class T>
void Linkedlist<T>::comp(Car C){
	
	if(typeid(T)==typeid(Car)){
	
		Node<T>*temp = head ;
		Node<T>*temp2;
		int c=0;
		while(temp!=NULL){
			if(temp->obj>C){
				if(temp->obj==C){
					cout << "\nHere is the vehicle of your choice..Go to main menu to book" << endl;
					temp->obj.printData();
					return ;
				}
				temp2= temp;
				c=1;
			}
	
			temp = temp->next ;
		}
		if(c==1){
			cout << "\nSorry your color preference could not be fulfilled" << endl;
			cout << "Here is the vehicle of your choice..Safe journey ahead" << endl;
			temp2->obj.printData();
			return ;
		}
		cout << "\nSorry we do not have any car that can mark upto expected preferences" << endl;
		return;
	}

}

