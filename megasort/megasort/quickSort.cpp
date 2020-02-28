#include <iostream>
#include "Header.h"
using namespace std;

void printArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void quickSort(int arr[], int l, int r) {
	if (l < r) {
		int pivot = partition(arr, l, r);
		quickSort(arr, pivot + 1, r);
		quickSort(arr, l, pivot - 1);
	}
}

int partition(int arr[], int l, int r) {
	int pivot = arr[l];
	int l0 = l;
	l++;
	while (l < r) {
		cout << "l is " << l << " r is " << r << endl;
		while ((arr[l] <= pivot) && (l < r))l++;
		while ((arr[r] > pivot) && (l < r))r--;
		swap(arr[l], arr[r]);
		printArr(arr, 10);
	}
	swap(arr[l - 1], arr[l0]);
	lump(arr, l - r + 1, l);
	return l - 1;
}

void lump(int arr[], int size, int l) {
	int k = 1;
	for (int i = 0; i < size; i++) {
		if (arr[i] == arr[l]) {
			swap(arr[l - k], arr[i]);
			k++;
		}
	}
	cout << "lumped" << endl;
	printArr(arr, 10);
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
	cout << "swapped" << endl;
}
