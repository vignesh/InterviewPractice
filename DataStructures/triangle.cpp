#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int getTraingleEdges(int input[], int len) {
	sort(input); //Fix: Call this properly
	vector<int>result;
	for(int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			for (int k = j + 1; k < len; k++) {
				if (input[i] + input[j] > input[k]) {
					list<int>triangle;
					triangle.push_back(input[i]);
					triangle.push_back(input[j]);
					triangle.push_back(input[k]);
					result.push_back(triangle); //FIX:cannot push a non-const value into a vector
				}
			}
		}
	}
}

int main () {

}