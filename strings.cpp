#include <iostream>
#include <string>
#include <map>
using namespace std;

int reverseString(string a) {
	int len = a.length();
	char copy[len]; 
	for (int i = 0; i < len; i++) {
		copy[i] = a[len-i];
		cout << copy[i];
	}
	return 0;
}

string reverseWords(string sentence) {
	return 0;
}

int stringToInteger(char *input) {
	int sign = 1;
	int i = 0;
	int sum = 0;
	if (input[i] == '-') {
		sign = -1;
		i = 1;
	}
	while (input[i] != '\0') {
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

/*string longestPalindrome(string word) {
	int len = word.length();
	int max = 0;
	int low = 0;
	int high = 0;
	for (int i = 1; i < len; ++i) {
		low = i - 1;
		high = i;
		while (low >= 0 && high < len && word[low] == word[high]) {
			if (high - low > max) {
				start = low;
				max = high - low - 1;
			}
		}
	}

	for (int i = 1; i < len; ++i) {
		low = i - 1;
		high = i + 1;
		while (low >= 0 && high < len && word[low] == word[high]) {
			if (high - low > max) {
				start = low;
				max = high - low - 1;
			}
		}
	}
	return 0;
}*/


int main() {
	//int value = stringToInteger("-100232");
	//cout << value << endl;
	//int isoValue = isomorphicStrings("abab", "xyxy");
	//cout << isoValue << endl;
	reverseString("abcdefg");
}
