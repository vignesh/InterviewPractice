#include <iostream>

using namespace std;

class Stack {

private: 
	int head;
	int length;

public:
		int *p;
	Stack(int size);
	~Stack();
	int pop();
	void push(int data);
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

int Stack::pop() {
	int value;
	value = p[head];
	head--;
	return value;
}

void Stack::push(int data) {
	head++;
	p[head] = data;
}

void Stack::printStack() {
	for (int i = 0; i <= head; i++) {
		cout << p[i] << " ";
	}
}

int main() {
	Stack s1(4);
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(6);
	s1.push(7);
	s1.push(8);
	s1.push(9);
	s1.push(10);
	s1.pop();
	s1.printStack();
}

