#include <iostream>
#include "tree.h"
#include "queue.h"

using namespace std;
void testTree(tree* t1, int[], int size);
void test(queue<int> &q1);
void testQueue(queue<int>* q1);

int main() {
	tree t1;
	queue<int> q1;

	testQueue(&q1);
	test(q1);

	int arr[16] = { 7,3,11,1,5,9,13,0,2,4,6,8,10,12,14};
	testTree(&t1, arr, 16);

	t1.reverseOrderTrasversal();

	cout << endl << endl;
	t1.printTreeRot(true);
	cout << endl << endl;
	t1.printTree();
	int num = 69;
	cout << num;  (t1.exist(num) == true) ? cout << " exists" << endl : cout << " do not exist" << endl;
	

	cout << "Lowest val is " << t1.findLowestVal(t1.root) << endl;
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////


void testQueue(queue<int>* q1) {
	q1->push_to_back(2);
	q1->push_to_back(3);
	q1->push_to_back(4);
	q1->push_to_back(5);
	q1->push_to_back(3);
	q1->push_to_back(2);
	cout << "Queue filled!" << endl;
	q1->printQueue();
}

void test(queue<int> &q1) {
	q1.pop_from_front();
	q1.printQueue();
	return;
}

void testTree(tree* t1, int arr[], int size) {
	for (int i = 0; i< size; i++) {
		cout << arr[i] << endl;
		t1->insertTreeNode(arr[i]);
	}
	cout<<"Lowest val is "<< t1->findLowestVal(t1->root) <<endl;
	cout << "Tree filled!" << endl;
	t1->inOrderTrasversal();
	cout << endl;
}

