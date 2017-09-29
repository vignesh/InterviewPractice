#include <iostream>
#include <ctime> //library only used for testing purposes

using namespace std;

typedef struct Unit {
    string value = "\0";
}Unit; //define unit within every hashTable index

class hashClass {
    
public:
    Unit *hashTable;
    hashClass (int size) {hashTable = new Unit[size];} //construct hashTable
    ~hashClass () {}
    int tableSize;
    int inputCounter = 0;
    int collisionCounter = 0;
    
    float load () {
        float factor = inputCounter/(float)tableSize;
        return factor;
    }//calculates load factor
    
    unsigned hashFunction (string key) {
	    unsigned hash = 0;
        int i = 0;
        while (key[i] != '\0') {
            hash = 33 * hash ^ key[i];
            i++;
        }
        hash = hash%tableSize;
        return hash;
    }//given a string will return a hash index

    unsigned collisionFix (unsigned index, string input) {
        unsigned newHash = 2166136261;
        while (hashTable[index].value != "\0") {
            newHash = (newHash * 16777619)^index;
            index += newHash;
            index = index%tableSize;
        }
        hashTable[index].value = input;
        return index;
    }//recalcualtes new hasindex if there is a collision
    
    bool set (unsigned index, string input) {
        float loadFactor = load();
        if (loadFactor >= 1) {
            return false;
        }
        if (hashTable[index].value == "\0") {
            inputCounter++;
            hashTable[index].value = input;
            return true;
        }
        else {
            inputCounter++;
            collisionCounter++;
            collisionFix(index, input);
            return true;
         }
        return false;
    }//inserts the string at the appropriate index
    
    
    string getValue (string key) {
        int index = hashFunction(key);
        if (hashTable[index].value == key) {
            return hashTable[index].value;
        }
        else {
            int newIndex = collisionFix(index, key);
            return hashTable[newIndex].value;
        }
    }//gets hash index value of key
    
    string deleteValue (string key) {
        int index = hashFunction(key);
        if (hashTable[index].value == "\0") {
            return hashTable[index].value;
        }
        else if (hashTable[index].value == key) {
            string temp = hashTable[index].value;
            hashTable[index].value = "\0";
            return temp;
            }
        else {
            int newIndex = collisionFix(index, key);
            string temp = hashTable[newIndex].value;
            hashTable[newIndex].value = "\0";
            return temp;
        }
    }//deletes value of a key
};

string stringGenerator (int averageSize) {

	static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

	int randomLength = rand() % averageSize;
	char random[randomLength];
	for (int i = 0; i < randomLength; i++) {
		random[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}
	return random;
}//generates random string


int main() {
    int inputSize;
    int strLength;
    cout << "How many strings do you want to insert?" << endl;
    cin >> inputSize;
    cout << "What is the average length of the string?" << endl;
    cin >> strLength;
    
    strLength =  strLength * 2;
    int tableSize = inputSize * 2;
	hashClass hashObject(tableSize);
    hashObject.tableSize = tableSize;
    
	srand(time(0));
    clock_t startTime = clock();
    
   for (int i = 0; i < inputSize; i++) {
    	string key = stringGenerator(strLength);
        int index = hashObject.hashFunction(key);
        hashObject.set(index, key);
	}//create and insert string into hashTable
    
    clock_t endTime = clock();
    clock_t duration = endTime - startTime;
    double timeInSeconds = duration/(double) CLOCKS_PER_SEC;
    cout << "Time In Seconds: " << timeInSeconds << endl;
    cout << "Number of Inputs: " << hashObject.inputCounter << endl;
    cout << "Number of Collisions: " << hashObject.collisionCounter << endl;
    
    return 0;
}
