#pragma once
#include <iostream>
class treeNode;
class queueNode {
public:
	queueNode(treeNode *a) { val = a; next = NULL; }
	queueNode() { val = NULL; next = NULL; }
	friend class queue;
	friend class tree;
	friend class treeNode;
	


	treeNode *val;
	queueNode* next;
};


class queue {
public:
	queue() { head = NULL; size = 0; }
	~queue() { while (size > 0) pop_from_front(); }
	void push_to_back(treeNode* a);
	void pop_from_front();
	void printQueue();


	queueNode* head;
	int size;
};
/*
class listNode;

class list{
public:
	listNode* head;
	list() { head = NULL; }
	~list() { while (head != NULL) pop_from_front(); }
	void printList();
	void push_to_front(int);
	void pop_from_front();
	int size;
};

class listNode {
public:
	int item;
	listNode* next;
	listNode(int a) {
		item = a;
		next = NULL;
	}
};
*/
#include "queue.hpp"