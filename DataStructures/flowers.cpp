#include <iostream>
#include <vector>
using namespace std; 

bool canPlaceFlowers(vector<bool> flowerbed, int flowersToPlant) {
	int counter = 0;
	if (flowersToPlant == 0) {
		return true;
	}
	if (flowersToPlant < 0) {
		return false;
	}
	for (int i = 0; i < flowerbed.size(); i++) {
		if (flowerbed[i] == 0 && flowerbed[i-1] != 1 && flowerbed[i+1] != 1) {
			flowerbed[i] = 1;
			counter++; 
		}
		if (counter == flowersToPlant) {
			return true;
		}
	}
	return false;
}

int main () {
	vector<bool> flowerbed;
	flowerbed.push_back(1);
	flowerbed.push_back(0);
	flowerbed.push_back(0);
	flowerbed.push_back(1);
	flowerbed.push_back(0);
	flowerbed.push_back(0);
	flowerbed.push_back(1);
	flowerbed.push_back(0);
	flowerbed.push_back(0);
	int value = canPlaceFlowers(flowerbed, 1);
	cout << value;
	int value2 = canPlaceFlowers(flowerbed, 2);
	cout << value2;
}