#include "queue.h"
#include "tree.h"
#include <iostream>
#include <cmath>
using namespace std;



int tree::findNumSpace(int height) {
	return pow(2, height) - 1;
}


void tree::printZero(int n) {
	for (int i = 0; i < n; i++) cout << "  ";
}

void tree::printVert(int n, int height, queue<int> &levelCode) {
	queueNode<int>* temp = levelCode.head;
	int j = 0;
	int factor;
	if (height == findTreeHeight()) return;

	for (int i = 0; i <= n / 2; i++) {
		j = 0;

		while (j < pow(2, height)) {
			printZero(n -i - 1);
			(temp->val == 1) ? cout << "/" : cout << " ";
			temp = temp->next;
			printZero(i * 2 + 1);
			(temp->val == 1) ? cout << "\\" : cout << " ";
			j++;
			printZero(n - i + 1);
			temp = temp->next;
		}
		temp = levelCode.head;
		
		cout << endl;
	}
	//cout << "bye" << endl;
}

void tree::printTree() {
	queue<treeNode*>* q1 = new queue<treeNode*>();
	treeNode* tptr = root;
	enqueue(tptr, q1);
	queueNode<treeNode*>* qptr = q1->head;
	while (tptr->val != findLowestVal(root)) {
		tptr = qptr->val;
		enqueue(tptr, q1);
		//q1->printQueue();
		qptr = qptr->next;
	}
	printTreeFromQueue(q1);
}


void tree::printTreeFromQueue(queue<treeNode*>* q1) {
	queue<int> levelCode;
	queueNode<treeNode*>* qptr = q1->head;
	int height = findTreeHeight();
	int val;
	for (int i = height; i >= 0; i--) {
		printZero(findNumSpace(i));
		for (int j = 0; j < pow(2, height - i) && q1->head != NULL; j++) {

			val = (qptr->val->left != NULL)? 1:0;
			levelCode.push_to_back(val);
			val = (qptr->val->right != NULL) ? 1 : 0;
			levelCode.push_to_back(val);

			if (qptr->val->containNum == true) cout << qptr->val ;
			else cout << "x ";

			printZero(findNumSpace(i + 1));
			qptr = qptr->next;
			q1->pop_from_front();
		}
		cout << endl;
		printVert(findNumSpace(i), height - i, levelCode);
		
		while (levelCode.head != NULL) levelCode.pop_from_front();
	}
}

void tree::enqueue(treeNode* node, queue<treeNode*>* q1) {
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
