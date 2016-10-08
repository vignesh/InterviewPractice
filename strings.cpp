#include <iostream>
#include <string>
#include <map>
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

/*int integerToString(int input) {
	int sign = 1;
	int i = 0;
	char s[100];
	int sum = 0;
	if (0 > input) {
		sign = -1;
	}

}*/

bool isomorphicStrings(string a, string b) {
    int i = 0;
    int j = 0;
    int lenA = a.length();
    int lenB = b.length();
    if (a == b) {
    	return false;
    }
    map<char,char> mapA;
    map<char,char> mapB;
    for (int i = 0; i < lenA; i++) {
    	if ((mapA.find(a[i]) == mapA.end()) && (mapB.find(b[i]) == mapB.end())) {
    		cout << "IN HERE" << endl;
    		mapA[a[i]] = b[i];
    		mapB[b[i]] = a[i];
    	}
    	else if ((mapA[a[i]] != b[i]) || (mapB[b[i]] != a[i])) {
    		//cout << "HELLO";
    		return false;
    	}
    	else { 
    	cout << "COUNTER" <<  " " << i << endl;
    	cout << mapA[a[i]] << " " << b[i] <<  endl;
    	cout << mapB[b[i]] << " " << a[i] << endl;
    	}
    }
    return true;
}

string longestPalindrome(string a) {
	return 0;
}

string sortInfiniteStream(string a) {
	return 0;
}

int main() {
	//int value = stringToInteger("-100232");
	//cout << value << endl;
	int isoValue = isomorphicStrings("abab", "xyxy");
	cout << isoValue << endl;
}
