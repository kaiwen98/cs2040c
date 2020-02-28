#pragma once
#include <iostream>

class treeNode;
class queue;


class tree {
public:
	tree();
	treeNode* insertTreeNode(int a, treeNode*);
	treeNode* insertTreeNode(int a) { return insertTreeNode(a, root); }
	void inOrderTrasversal() { inOrderTrasversal(root); }
	void inOrderTrasversal(treeNode*);
	void preOrderTrasversal() { preOrderTrasversal(root); }
	void preOrderTrasversal(treeNode*);
	void postOrderTrasversal() { postOrderTrasversal(root); }
	void postOrderTrasversal(treeNode*);
	void enqueue(treeNode* node, queue* q1);
	void printTree();
	int findMaxVal();
	int findNumSpace(int);
	int findTreeHeight();
	void printTreeFromQueue(queue*);
	void printZero(int);
	void printVert(int, int);
	int findLowestVal(treeNode*);
	treeNode* root;
};

class treeNode {
public:
	treeNode(int a);
	treeNode(int a, bool);
	int findHeight();
	friend class tree;
	bool containNum;

	int val;
	treeNode* left;
	treeNode* right;
};

#include "tree.hpp"
#include "tree2.hpp"