#ifndef TRY_H
#define TRY_H

using namespace std;
#include <iostream>
#include <fstream>
template <class T>
class Node {
	private:
		T obj ;
		Node<T>* next ;
		Node<T>* prev ;
	public:
		Node();
		Node(T a);
		//~Node();
		
	template <class Y> friend class Linkedlist ;
};

template <class T>
class Linkedlist {

	private:
		Node<T> *head ;
		Node<T> *tail ;
	public:
		
		bool isempty();
		void add(T);
		const int check(const string );
		void remove(const string );
		const int transport(int , const int);
		int travel(int);
		int carTravel(int);
		int printData(const string );
		void comp(Car);
		Linkedlist();
		~Linkedlist();
		void change_status(const int , const string );
		const bool printbook(const int);
};

#endif
