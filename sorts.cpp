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

void quicksort(int data[], int left, int right) {
	int i = left;
	int j = right;
	int temp;
	int pivot = data[(i+j)/2];
	while (i <= j) {
		while (i < pivot) {
			i++;
		}
		while (j > pivot) {
			j--;
		}
		if (i <= j) {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
			i++;
			j--;
		}
		if (left < j) {
			quicksort(data, left, j);
		}
		if (i < right) {
			quicksort(data, i, right);
		}
	}
	//for (int k = 0; k < 4; k++) {
	//	cout << data[k] << " ";
	//}
}
//O(nlogn), unstable, worst case O(n^2)

int main () {
	int data [5] = {10, 20, 30, 5, 3}; 
	quicksort(data, 0, 4);
	//int val =selectionSort(data, 5);	
	//cout << val;
}

//mergesort
//quicksort
//selectionsort 
//insertionsort
//bucketsort 
