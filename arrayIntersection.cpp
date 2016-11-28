#include <iostream>
using namespace std;

int intersectionSortedArrays(int array1[], int array2[]) {
	int len1 = array1.length();
	int len2 = array2.length();
	int i = 0;
	int j = 0;
	while (i <= len1 && j <= len2) {
		if (array1[i] < array2[j]) {
			i++;
		}
		else if (array1[i] > array2[j]) {
			j++;
		}
		else {
			cout << array1[i] << endl; 
		}
	}
}

int main () {
	int data [5] = {1, 2, 3, 4, 5}; 
	int data2 [5] = {3, 4, 5, 6, 7}; 
	intersectionSortedArrays(data, data2);
    
}
