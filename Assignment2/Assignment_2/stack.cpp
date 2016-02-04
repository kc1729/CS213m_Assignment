#include "stack.hpp"
#include <iostream>

using namespace std;

template<class T>
stack<T>::stack(){
	this->num = 0;
}

template<class T>
stack<T>::stack(const stack &to_copy_to){
	this->elements = to_copy_to.elements;
	this->num = to_copy_to.num;
}

template<class T>
stack<T>::~stack(){
}

template<class T>
void stack<T>::push(T n){
	T* dummy = &n;
	this->elements.push_front(*dummy);
	this->num++;
}

template<class T>
int stack<T>::top(T *top_element){
	if(elements.empty()){
		return -1;
	}

	*top_element = *(this->elements.begin());
	return 1;
}

template<class T>
void stack<T>::pop(){
	if(!elements.empty()){
	this->elements.pop_front();
	this->num--;
	}
}

template<class T>
int stack<T>::size(){
	return this->num;
}