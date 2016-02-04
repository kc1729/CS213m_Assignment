#include "queue_list.hpp"
#include <iostream>

using namespace std;

template<class T>
queue_list<T>::queue_list(){
this->num = 0;
}

template<class T>
queue_list<T>::queue_list(const queue_list &to_copy_to){
	this->q = to_copy_to.q;
	this->num = to_copy_to.num;
}

template<class T>
queue_list<T>::~queue_list(){
}

template<class T>
void queue_list<T>::push_back(T n){
	T* dummy = &n;
	this->q.push_back(*dummy);
	this->num++;
}

template<class T>
int queue_list<T>::front(T *top_element){
	if(q.empty()){
		return -1;
	}

	*top_element = *(this->q.begin());
	return 1;
}

template<class T>
void queue_list<T>::pop_front(){
	if(!q.empty()){
	this->q.pop_front();
	this->num--;
	}
}

template<class T>
int queue_list<T>::size(){
	return this->num;
}