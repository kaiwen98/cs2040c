#include <iostream>
#include "tree.h"
#include "queue.h"

using namespace std;
void testTree(tree* t1, int[], int size);

int main() {
	tree t1;
	int arr[8] = { 6,2,3,4,5,1,7,8};
	testTree(&t1, arr, 8);
	t1.printTree();
	cout << "Lowest val is " << t1.findLowestVal(t1.root) << endl;
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////


/*void testQueue(queue* q1) {
	q1->push_to_back(2);
	q1->push_to_back(3);
	q1->push_to_back(4);
	q1->push_to_back(5);
	q1->push_to_back(3);
	q1->push_to_back(2);
	cout << "Queue filled!" << endl;
	q1->printQueue();
}*/

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

