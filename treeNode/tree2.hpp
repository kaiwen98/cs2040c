#pragma once

#ifndef TREE2HPP
#define TREE2HPP

#include "tree.h"
#include "queue.h"
#include <iostream>
#include <cmath>
using namespace std;

void tree::printTree() {
	queue* q1 = new queue();
	treeNode* tptr = root;
	enqueue(tptr, q1);
	queueNode* qptr = q1->head;
	while (tptr->val != findLowestVal(root)) {
		tptr = qptr->val;
		enqueue(tptr, q1);
		q1->printQueue();
		qptr = qptr->next;
	}
	printTreeFromQueue(q1);
}

int tree::findNumSpace(int height) {
	return pow(2, height) - 1;
}


void tree::printZero(int n) {
	for (int i = 0; i < n; i++) cout << "  ";
}

void tree::printVert(int n, int height) {
	int j = 0;
	int factor;
	if (height == findTreeHeight()) return;
	for (int i = 0; i <= n/2; i++) {
		j = 0;
		
		while (j < pow(2, height)) {
			printZero((n - i - 1));
			cout << "/";
			printZero(i * 2 + 1);
			cout << "\\";
			j++;
			printZero(n - i +1);
		}
		cout << endl;
	}
	

}

void tree::printTreeFromQueue(queue* q1) {
	list levelCode;
	queueNode* qptr = q1->head;
	int height = findTreeHeight();
	for (int i = height; i>=0; i--) {
		printZero(findNumSpace(i));
		for (int j = 0; j < pow(2,height-i) && q1->head != NULL; j++) {

			if (qptr->val->containNum == true) {
				cout << qptr->val->val << " ";
				levelCode.push_to_front(1);
			}
			else {
				cout << "x ";
				levelCode.push_to_front(0);
			}
			printZero(findNumSpace(i + 1));
			qptr = qptr->next;
			q1->pop_from_front();
		}
		cout << endl;
		printVert(findNumSpace(i), height - i);
		levelCode.printList();
		while (levelCode.head != NULL) levelCode.pop_from_front();
	}
}

void tree::enqueue(treeNode* node, queue* q1) {
	if (q1->size == 0) q1->push_to_back(node);

	else {
		//if (node->containNum == false) return;
		if (node->left == NULL) {
			treeNode* dummyNode = new treeNode(0, false);
			q1->push_to_back(dummyNode);
		}
		else q1->push_to_back(node->left);

		if (node->right == NULL) {
			treeNode* dummyNode = new treeNode(0, false);
			q1->push_to_back(dummyNode);
		}
		else q1->push_to_back(node->right);
	}
}

#endif