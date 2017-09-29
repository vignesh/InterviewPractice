#include <iostream>
using namespace std;

void balanceSum(int array[], int length) {
	//int length = sizeof array/sizeof array[0];
	int totalSum = 0;
	int sum = 0;
	int j = 0;
	for (int i = 0; i < length; i++) {
		totalSum += array[i];
	}
	for (int j = 0; j < length; j++) {
		totalSum -= array[j];
		//cout << j << endl;
		if (totalSum == sum) {
			cout << j << endl;
			break;
		}
		sum += array[j];
	}
	if (totalSum != sum) {
		cout << "No balance point";
	}
}

int main () {
	int data [5] = {1, 2, 0, 0, 3}; 
	balanceSum(data, 5);
}