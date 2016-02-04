#include "queue_vector.hpp"
#include <iostream>

using namespace std;

template<class T>
queue_vector<T>::queue_vector(){
this->num = 0;
}

template<class T>
queue_vector<T>::queue_vector(const queue_vector &to_copy_to){
	this->v = to_copy_to.v;
	this->num = to_copy_to.num;
}

template<class T>
queue_vector<T>::~queue_vector(){
}

template<class T>
void queue_vector<T>::push_back(T n){
	T* dummy = &n;
	this->v.push_back(*dummy);
	this->num++;
}

template<class T>
int queue_vector<T>::front(T *top_element){
	if(v.empty()){
		return -1;
	}

	*top_element = *(this->v.begin());
	return 1;
}

template<class T>
void queue_vector<T>::pop_front(){
	if(!v.empty()){
	this->v.erase(v.begin());
	this->num--;
	}
}

template<class T>
int queue_vector<T>::size(){
	return this->num;
}