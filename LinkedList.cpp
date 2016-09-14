#include<iostream>
using namespace std;

class LinkedList {

	struct Node {
		Node *next;
		int data;
	};

public:
	Node *head;	
	LinkedList() {head = NULL;}
	//~LinkedList();

	void addFrontNode (int value) {
		Node *newNode = new Node();
		newNode->data = value;
		newNode->next = head;
		head = newNode;
	}

	void addLastNode (Node *head, int value) {
		int storeValue = value;
		if (head != NULL) {
			Node *temp = head->next;
			addLastNode(temp, storeValue);
		}
		else {
			Node *newNode = new Node();
			head->next = newNode;
			newNode->data = value;
			newNode->next = NULL;
		}
	}

	void inOrderPrint () {
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

	void reversePrint (Node *head) {
		if (head != NULL) {
			Node *temp = head->next;
			reversePrint(temp);
			cout << head->data << endl;
		}
	}
};

int main() {
    LinkedList list;

    list.addFrontNode(5);
    list.addFrontNode(10);
    list.addFrontNode(15);
    list.popFirstValue();
    list.inOrderPrint();
    list.reversePrint(Node *head);

    return 0;
}

