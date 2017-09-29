#include <iostream>
using namespace std;

int allFactors(int number) {
	for (int i = 1; i <= number; i++) {
		if (number%i == 0) {
			cout << i << " " << endl;
		}
	}
	return 0;
}

int primeFactors(int number) {
	while (number%2 == 0) {
		cout << 2 << endl;
		number = number/2;
	}
	for (int i = 3; i < number/i; i = i + 2) {
		while (number%i == 0) {
			cout << number << ":" << i << " ";
			number = number/i;
		}
	}
	if (number > 2) {
		cout << number << " ";
	}
	return 0;
} 

int kthLargestNumber () {
	return 0;
}

int sumInArray (int sum) {
	return 0;
}//are two numbers in an array = to sum

int findMedian (int arr[], int arr2[], int n) {

}//find median given two arrays

int main() {
	//allFactors(30);
	primeFactors(315);
}