#include <iostream>
using namespace std;

class Queue {

private:
	int *p;
	int head;
	int tail;
	int length;

public: 
	Queue(int size);
	~Queue();
	int enqueue (int data);
	int dequeue();
	void printQueue();
};

Queue::Queue (int size) {
	tail = -1;
	head = -1;
	length = size;
	p = new int[length];
}

Queue::~Queue () {
	delete [] p;
}

int Queue::enqueue(int data) {
	if (tail == length) {
		cout << "Full Queue" << endl;
		return 0;
	}
	tail++;
	p[tail] = data;
	return 0;
}

int Queue::dequeue() {
	if (head == tail) {
		cout << "Empty Queue" << endl;
		return 0;
	}
	head++;
	int value = p[head];
	return value;
}

void Queue::printQueue() {
	for (int i = head + 1; i <= tail; i++) {
		cout << p[i] << " ";
	}
}

int main() {
	Queue q1(5);
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(5);
	q1.dequeue();
	q1.printQueue();
}
