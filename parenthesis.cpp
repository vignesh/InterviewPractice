#include <iostream>
using namespace std;

bool checkParenthesis(string input) {
	int count = 0;
	int len = input.length();
	if (len == 0) {
		return true;
	}
	for (int i = 0; i < len; i++) {
		if (input[i] == '(') {
			count++;
		}
		else if (input[i] == ')') {
			count--;
			if (count < 0) {
				return false;
			}
		}
	}
	if (count  == 0) {
		return true;
	}
	return false;
}

int main () {
	int value = checkParenthesis("())(()()()");
	cout << value;
}