#include <iostream>
using namespace std;

void printArr(int[], int);
void mergeSort(int[], int, int);
void merge(int[], int, int, int);


int main() {
	int arr[10] = { 2,5,6,7,4,7,11,3,4,69 };

	mergeSort(arr, 0, 9);
	printArr(arr, 10);
	return 0;
}

void printArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void mergeSort(int arr[], int l, int r) {

	if (l < r) {
		int m = (l + (r - 1)) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void merge(int arr[], int ll, int m, int rr) {
	int k = 0, c[50];
	//int n1 = m - ll + 1;
	//int n2 = rr - m;
	int l = ll, r = m + 1;
	while ((l <= m) && (r <= rr)) {
		if (arr[l] < arr[r]) {
			c[k] = arr[l];
			l++;
		}
		else {
			c[k] = arr[r];
			r++;
		}
		k++;
		printArr(c, rr - ll + 1);
	}

	while (r <= rr) {
		c[k] = arr[r];
		r++; k++;
	}

	while (l <= m) {
		c[k] = arr[l];
		l++; k++;
	}


	printArr(c, rr - ll + 1);

	for (int i = 0; i < rr - ll + 1; i++) {
		arr[ll + i] = c[i];
	}
}