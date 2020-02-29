#include "tree.h"
#include "queue.h"
#include <iostream>
#include <cmath>
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

int tree::findMaxVal() {
	treeNode* temp = root;
	while (temp->right != NULL) {
		temp = temp->right;
	}
	return temp->val;
}

int tree::findLowestVal(treeNode* node) {
	if (node->left == NULL && node->right == NULL) return node->val;
	else if (node->right != NULL && node->left == NULL) {
		return findLowestVal(node->right);
	}
	else if (node->right == NULL && node->left != NULL) {
		return findLowestVal(node->left);
	}
	else {
		if (node->left->findHeight() > node->right->findHeight()) {
			return findLowestVal(node->left);
		}
		else {
			return findLowestVal(node->right);
		}
	}
}

int treeNode::findHeight() {
	int leftHeight = (left == NULL) ? -1 : left->findHeight();
	int rightHeight = (right == NULL) ? -1 : right->findHeight();
	return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

int tree::findTreeHeight() {
	return root->findHeight();
}

void tree::inOrderTrasversal(treeNode* node) {
	if (node->left != NULL) inOrderTrasversal(node->left);
	cout << node->val << " ";
	if (node->right != NULL) inOrderTrasversal(node->right);
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

ostream& operator<<(ostream& os, treeNode* node) {
	os << node->val;
	return os;
}
