#pragma once
#ifndef QUEUEHPP
#define QUEUEHPP
#include "queue.h"
#include <iostream>
using namespace std;

void queue::push_to_back(treeNode* a){
	if (size == 0) head = new queueNode(a);

	else {
		queueNode* prev = head;
		queueNode* temp = head->next;
		while (temp != NULL) {
			temp = temp->next;
			prev = prev->next;
		}
		temp = new queueNode(a);
		prev->next = temp;
	}
	size++;
}

void queue::pop_from_front() {
	queueNode* temp = head;
	head = head->next;
	delete temp;
	size--;
}

void list::pop_from_front() {
	listNode* temp = head;
	head = head->next;
	delete temp;
	size--;
}

void queue::printQueue() {
	queueNode* temp = head;
	while (temp != NULL) {
		cout << temp->val->val << " ";
		temp = temp->next;
	}
	cout << endl;
}

void list::push_to_front(int item) {
	listNode* temp = new listNode(item);
	temp->next = head;
	head = temp;
	size++;
}

void list::printList() {
	listNode* temp = head;
	while (temp != NULL) {
		cout << temp->item << " ";
		temp = temp->next;
	}
	cout << endl;
}


#endif
