#include "queue.h"
#include "tree.h"
#include <iostream>
#include <cmath>
using namespace std;

void tree::printTreeRot(treeNode* node, bool printHeight) {
	if(node->right != NULL) printTreeRot(node->right, printHeight);
	if(node != NULL) printNode(node, printHeight);
	if(node->left != NULL) printTreeRot(node->left, printHeight);
	return;
}

void tree::printNode(treeNode* node, bool printHeight) {
	printZero(5*(findTreeHeight() - node->findHeight()));
	cout << node->val;
	(printHeight == true) ? cout << "(h = " << node->findHeight() << ")":cout<<"";
	cout << endl;
}