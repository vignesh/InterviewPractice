#include<iostream>
using namespace std;

class LinkedList {

	struct Node {
		Node *next;
		int data;
	};

private:
	Node *head;	

public:
	LinkedList() {head = NULL;}
	//~LinkedList();

	void addFrontNode (int value) {
		Node *newNode = new Node();
		newNode->data = value;
		newNode->next = head;
		head = newNode;
	}

	void PrintLinkedList () {
		Node *temp = head;
		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}

	void popFirstValue () {
		Node *temp = head;
		int value = temp->data;
		head = head->next;
		delete temp;
	}

};

int main() {
    LinkedList list;

    list.addFrontNode(5);
    list.addFrontNode(10);
    list.addFrontNode(15);
    list.popFirstValue();
    list.PrintLinkedList();

    return 0;
}

