#include <iostream>
#include "Header.h"
using namespace std;

int main() {
	int arr[10] = { 1,4,5,3,6,22,4,5,7,34 };
	printArr(arr, 10);

	quickSort(arr, 0, 9);
	printArr(arr, 10);
	return 0;
}