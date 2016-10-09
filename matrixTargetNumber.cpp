#include <iostream>
using namespace std;

bool findTarget(int **matrix, int target) {
	int row = 0;
	int cols = 0;
	int collen = sizeof matrix[0]/sizeof(int);
	int rowlen = sizeof matrix/sizeof matrix[0];
	while (row < rowlen && cols < collen) {
		if (matrix [row][cols] == target) {
			return true;
		}
		else if (matrix[row][cols] < target) {
			row++;
		}
		else {
			cols++;
		}
	}
	return false; 
}

int main() {

}//need to create a test case