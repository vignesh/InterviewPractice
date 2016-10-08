#include <iostream>
using namespace std;

void swap(int data[], int index1, int index2) {
	if (index1 != index2) {
		int holder = data[index1];
		data[index1] = data[index2];
		data[index2] =  holder;
	}
}

int selectionSort(int data[], int len) {
	//int len =  (sizeof(data)/sizeof(*data));
	for (int i = 0; i < len - 1; i++) {
		int minIndex = i; 
		for (int j = i+1; j < len; j++) {
			if (data[j] < data[i]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			swap(data, i, minIndex);
		}
	}
	return *data;
}//O(n^2), in place algorithm, unstable

int quickSort(int data[], int len) {
	int pivotIndex = len/2;
	int pivotValue = data[pivotIndex];
	int leftCounter = 0;
	for (int i = 0; i < len; i++) {
		if (data[i] < pivotValue) {
			leftCounter++;
		}
	}
	//int [] leftArray = new int[leftCounter];
	//int [] rightArray = new int[len-1-leftCounter];
}//O(nlogn), unstable


int main () {
	int data [5] = {10, 20, 30, 5, 3}; 
	int val =selectionSort(data, 5);	
	cout << val;
}

//mergesort
//quicksort
//selectionsort 
//insertionsort
//bucketsort 
