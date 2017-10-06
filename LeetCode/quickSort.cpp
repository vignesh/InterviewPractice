//Divide and Conquer Algorithm
//Best and AVeage time O(nlogn)
//Worst case time O(n^2)
//In place sorting, does not need extra space

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot-1);
		quickSort(arr, pivot+1, high);
	}
}

int parition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for (j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1],&swap[j])
	return i + 1;
}

int swap(int* a, int* b) {
	int* tmp = a;
	int* a = *b;
	int* b = tmp;
}