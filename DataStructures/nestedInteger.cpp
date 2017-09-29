#include <iostream>
#include <list>
using namespace std;

int depthSum(list<int> input, int level) {
	int sum = 0;
	int level = 1;
	for (int i = 0; i < input.size(); i++) {
		if (input[i].isInteger()) {
			sum += input[i] * level;
		}
		else {
			sum += depthSum(input[i].getList(), level + 1)
		}
	}
	return sum;
}

int main() {

}