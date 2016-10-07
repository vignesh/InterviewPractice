#include <iostream>
#include <string>
using namespace std;

int stringToInteger(char *input) {
	int sign = 1;
	int i = 0;
	int sum = 0;
	if (input[i] == '-') {
		sign = -1;
		i = 1;
	}
	while (input[i] != '\0') {
		//cout << i << " " << input[i] << " " << sum << endl;
		sum = sum * 10 + input[i] - '0';
		i++;
	}
	return (sum * sign);
}

int main() {
	int value = stringToInteger("-100232");
	cout << value << endl;
}
