#pragma once

#ifndef TEMPLATEHPP
#define TEMPLATEHPP

#include "tree.h"
#include "queue.h"
#include <iostream>
using namespace std;

treeNode::treeNode(int a, bool n) {
	val = a;
	left = NULL;
	right = NULL;
	containNum = n;
}

treeNode::treeNode(int a) {
	val = a;
	left = NULL;
	right = NULL;
	containNum = true;
}

tree::tree() {
	root = NULL;
}

treeNode* tree::insertTreeNode(int a, treeNode* node) {

	if (root == NULL) {
		root = new treeNode(a);
		cout << "new root made!" << endl;
	}
	else {
		cout << "height of the treeNode is: " << node->findHeight() << endl;
		if (a > node->val) {
			node->right = (node->right == NULL) ? node->right = new treeNode(a) : insertTreeNode(a, node->right);
		}
		else if (a < node->val) {
			node->left = (node->left == NULL) ? node->left = new treeNode(a) : insertTreeNode(a, node->left);
		}
	}
	return node;
}

int treeNode::findHeight() {
	int leftHeight = (left==NULL)?-1:left->findHeight();
	int rightHeight = (right==NULL)?-1:right->findHeight();
	return 1 + ((leftHeight > rightHeight )?leftHeight:rightHeight);
}

void tree::inOrderTrasversal(treeNode* node) {
	if (node->left != NULL) inOrderTrasversal(node->left);
	cout << node->val << " ";
	if(node->right!=NULL) inOrderTrasversal(node->right);
	return;
}

void tree::preOrderTrasversal(treeNode* node) {
	cout << node->val << " ";
	if (node->left != NULL) preOrderTrasversal(node->left);
	if (node->right != NULL) preOrderTrasversal(node->right);
	return;
}

void tree::postOrderTrasversal(treeNode* node) {
	if (node->left != NULL) postOrderTrasversal(node->left);
	if (node->right != NULL) postOrderTrasversal(node->right);
	cout << node->val << " ";
	return;
}

void tree::printTree() {
	queue q1;
	queueNode* qptr = q1->head;
	treeNode* tptr = t1->root;

	while (tptr != NULL) {
		enqueue(tptr, q1);
		qptr = qptr->next;
		tptr = qptr;
	}

	qptr = q1->head;

	for (int i = 1; qptr != NULL; i * 2) {
		for (int j = 0; j < i; j++) {
			cout << qptr->val->val << " ";
			qptr = qptr->next;
			q1->pop_from_head();
		}
		cout << endl;
	}
}

void tree::enqueue(treeNode* node, queue* q1) {
	if (q1->size == 0) q1->push_to_back(node);

	else {
		if (node->containNum == false) return;
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