#pragma once
#ifndef QUEUEHPP
#define QUEUEHPP
#include "queue.h"
#include "tree.h"
#include <iostream>
using namespace std;

template <class T>
void queue<T>::push_to_back(T a){
	if (size == 0) head = new queueNode<T>(a);

	else {
		queueNode<T>* prev = head;
		queueNode<T>* temp = head->next;
		while (temp != NULL) {
			temp = temp->next;
			prev = prev->next;
		}
		temp = new queueNode<T>(a);
		prev->next = temp;
	}
	size++;
}

template <class T>
void queue<T>::pop_from_front() {
	queueNode<T>* temp = head;
	head = head->next;
	delete temp;
	size--;
}



template <class T>
void queue<T>::printQueue() {
	queueNode<T>* temp = head;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}


#endif
