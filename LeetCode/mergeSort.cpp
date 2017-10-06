//Divide and Conquer Algorithm
//Best and AVeage time O(nlogn)
//Worst case time O(nlogn)
//Requires extra memory for temporary arrays

void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int leftTemp[n1];
	int rightTemp[n2];

	for (i = 0; l < m; l++) {
		leftTemp[i] = arr[l+i];
	}
	for (j = 0; j < r; j++) {
		leftTemp[j] = arr[l+m+j];
	}

	while (i < n1 && j < n2) {
		if (leftTemp[i] <= rightTemp[j]) {
			arr[k] = leftTemp[i];
			i++;
		}
		else {
			arr[k]= rightTemp[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = arr[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = arr[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r) {
	if (l > r) {
		int middle = (l+r)/2;
		mergeSort(int arr[], l, middle);
		mergeSort(int arr[], middle+ + 1, r)

		merge(int arr[], l, middle, r);
	}
}
