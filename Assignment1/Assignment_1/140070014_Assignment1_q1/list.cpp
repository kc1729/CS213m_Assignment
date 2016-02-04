#include "list.hpp"
#include <iostream>

using namespace std;


Node* insert(Node* head, int val, int pos) {
	Node* mynode = NULL;
	mynode = new Node(val, NULL);

	Node* dummynode;

	dummynode = head;

	for (int i = 0; i < pos - 1; ++i) {
		dummynode = dummynode->getNext();
	}

	if(pos == 0) {
		mynode->setNext(head);
		return mynode;
	} else {
		mynode->setNext(dummynode->getNext());
		dummynode->setNext(mynode);
	}
	return head;
}

Node* remove(Node* head, int pos) {

	Node* dummynode = NULL;

	dummynode = head;

	if(pos == 0) {
		return head->getNext();
	}

	for (int i = 0; i < pos-1; ++i) {
		dummynode = dummynode->getNext();
	}

	dummynode->setNext(dummynode->getNext()->getNext());

	return head;

}

int size(Node* head) {

	int counter = 0;

	Node* dummynode = NULL;
	dummynode = new Node(0, NULL);

	dummynode = head;

	while(dummynode != NULL) {
		counter++;
		dummynode = dummynode->getNext();
	}

	return counter;
}

Node* reverse(Node* head) {

	Node* dummynode1 = NULL;
	dummynode1 = new Node(0, NULL);

	dummynode1 = head;

	Node* dummynode2 = NULL;

	Node* dummynode3 = NULL;
	dummynode3 = new Node(0, NULL);

	int count = size(head);

	for (int i = 0; i < count; ++i) {
		if(dummynode1->getNext() == NULL) {
			dummynode1->setNext(dummynode2);
			dummynode2 = dummynode1;
			return dummynode2;
		}

		dummynode3 = dummynode1->getNext(); 
		dummynode1->setNext(dummynode2);
		dummynode2 = dummynode1;
		dummynode1 = dummynode3;
	}
	return dummynode2;
}

int cycle_size(Node* head){
	
	int cycle_size = 1;

	Node* tortoise = head;
	Node* hare = head->getNext()->getNext();

	//cout<< hare->getVal() << " " << tortoise->getVal();

	while(hare != tortoise){
		//cout<<"in"<<endl;
		tortoise = tortoise->getNext();
		hare = hare->getNext()->getNext();
	}

	int dummy = tortoise->getVal();

	hare = hare->getNext();

	while(hare != tortoise){
		//cout<<"in+"<<endl;
		hare = hare->getNext();
		cycle_size++;
	}

	return cycle_size;
}


