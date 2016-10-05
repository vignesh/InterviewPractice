#include <iostream>

using namespace std;

class Stack {

private: 
	int *p;
	int head;
	int length;

public:
	Stack(int size);
	~Stack();
	int pop();
	int push(int data);
	void printStack();
};

Stack::Stack(int value) {
	head = -1;
	length = value;
	p = new int[length];
}

Stack::~Stack() {
	delete [] p;
}

int Stack::push(int data) {
	if (head == length) {
		cout << "Full Stack" << endl
		return 0;
	}
	head++;
	p[head] = data;
}

int Stack::pop() {
	if (head == 0) {
		cout << "Empty Stack" << endl;
		return 0;
	}
	int value;
	value = p[head];
	head--;
	return value;
}

void Stack::printStack() {
	for (int i = 0; i <= head; i++) {
		cout << p[i] << " ";
	}
}

int main() {
	Stack s1(5);
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.pop();
	s1.printStack();
}

