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
		/*Node *temp = head;
		while (temp != NULL) {
			temp = temp->next;
			cout << temp->next;
		}
		Node *newNode = new Node();
		newNode->data = value;
		newNode->next = NULL;*/
		//temp->next = newNode;

		if (head != NULL) {
			cout << head << endl;
			Node *temp = head->next;
			addLastNode(temp, storeValue);
		}
		if (head == NULL) {
			Node *newNode = new Node();
			newNode->data = value;
			newNode->next = NULL;
			head->next = newNode; 
		}
	}

	/*void addNthNode (Node *head, int value, int position) {
		int storeValue = value;
		if (postion != 0) {
			Node *temp = head->next;
			position = position - 1;
			addNthNode(temp, storeValue, position);
		}
	}*/

	void findMiddleNode (Node *head) {
		//if (*head != NULL) {
		//	Node *temp = head->next;
		//	findMiddleNode(temp);
		//}
		Node *slow = head;
		Node *fast = head;
		while (fast != NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}
		cout << slow->data << endl;
	};

	bool cycleCheck (Node *head) {
		if (head == NULL) {
			cout << "bye" << endl;
			return false;

		}
		Node *slow = head;
		Node *fast = head;
		while (slow != NULL && fast != NULL) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == head) {
				return true;
			}
		}
		cout << "hi" << endl;
		return false;
	};

	void reverseList();

	void inOrderPrint (Node *head) {
		if (head != NULL) {
			cout << head->data << endl;
			Node *temp =  head->next;
			inOrderPrint(temp);
		}
	}

	void reversePrint (Node *head) {
		if (head != NULL) {
			Node *temp = head->next;
			reversePrint(temp);
			cout << head->data << endl;
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

    list.addFrontNode(1);
    list.addFrontNode(2);
    list.addFrontNode(3);
    list.addFrontNode(4);
    list.addFrontNode(5);
    list.addFrontNode(6);
    list.popFirstValue();
    list.cycleCheck(list.head);
    //list.findMiddleNode(list.head);
    //list.addLastNode(list.head, 7);
    list.inOrderPrint(list.head);
    //list.reversePrint(list.head);

    return 0;
}

