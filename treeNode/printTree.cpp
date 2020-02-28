/*#include "tree.h"
#include "queue.h"
#ifndef PRINTTREECPP
#define PRINTTREECPP


using namespace std;

template <class T>
void printTree(tree& t1 , queue<T>* q1) {
	int initial = 0;
	queueNode* temp = q1->head;

	while (temp != NULL) {
		enqueue(temp, q1);
		temp = temp->next;
	}

	queueNode* temp = q1->head;

	for (int i = 1; temp != NULL; i * 2) {
		for (int j = 0; j < i; j++) {
			cout << temp->val << " ";
			temp = temp->next;
			q1->pop_from_head();
		}
		cout << endl;
	}
}

template <class T>
void enqueue(treeNode* node, queue<T>* q1) {
	if (q1->size == 0) q1->push_to_back(node);

	else {
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
*/