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
	return 0;
} 

int nthLargestNumber () {
	return 0;
}

int sumInArray (int sum) {
	return 0;
}//are two numbers in an array = to sum

int findMedian () {

}//find median given two arrays

int main() {
	allFactors(30);
}