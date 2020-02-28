/*#include <iostream>
#include "queue.h"
#include "tree.h"

#ifndef QUEUECPP
#define QUEUECPP

using namespace std;

template<class T>
void testQueue(queue<T> *q1) {
	q1->push_to_back(2);
	q1->push_to_back(3);
	q1->push_to_back(4);
	q1->push_to_back(5);
	q1->push_to_back(3);
	q1->push_to_back(2);
	cout << "Queue filled!" << endl;
	q1->printQueue();
}

template<class T>
void testTree(tree *t1) {
	t1->insertTreeNode(2);
	t1->insertTreeNode(3);
	t1->insertTreeNode(4);
	t1->insertTreeNode(5);
	t1->insertTreeNode(1);
	t1->insertTreeNode(3);
	t1->insertTreeNode(6);
	cout << "Tree filled!" << endl;
	t1->inOrderTrasversal();
	cout << endl;
}

#endif
*/