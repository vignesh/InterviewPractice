#include <iostream>
using namespace std;

class LinkedList {

	struct Node {
		Node *next; 
		Node *child;
		int data;
	};	

public:
	Node *head;	
	LinkedList() {head = NULL;}
	//~LinkedList();

	void addFrontNode (int value) {
		if (head == NULL) {
			Node *newNode = new Node();
			newNode->data = value;
			newNode->next = NULL;
			head = newNode;
		}
		else {
			Node *newNode = new Node();
			newNode->data = value;
			newNode->next = head;
			head = newNode;
		}
	}

	void addLastNode (int value) {
		Node *temp = head;
		Node *newNode = new Node();
		newNode->data = value;
		newNode->next = NULL;
		while (temp->next != NULL) {
			temp = temp->next; 
		}
		temp->next = newNode; 
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
		Node *slow = head;
		Node *fast = head;
		while (fast->next != NULL) {
			fast = fast->next;
			if(fast->next != NULL) {
				fast = fast->next;
			}
			slow = slow->next;
		}
		cout << "Middle Node " << slow->data << endl;
	};

	void cycleCheck () {
		Node *slow = head;
		Node *fast = head;
		while (slow->next != NULL && fast->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				cout << "Cycle" << endl;
			}
		}
		cout << "No Cycle" << endl;
	};

	Node* reverseList(Node *head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		Node *temp = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return temp;
	};

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
			cout << head->data << " ";
		}
	}

	void popFirstValue () {
		Node *temp = head;
		int value = temp->data;
		head = head->next;
		delete temp;
	}

	void flattenList (Node *head) {
		Node *temp;
		Node *tail = head;
		Node *current = head;
		while (tail != NULL) {
			tail = tail->next;
		}
		while (current != tail) {
			if (current->child) {
				tail->next = current->child;
				temp = current->child;
			}
			while (temp ) {
				temp = temp->next;
			}
			tail = temp;
		}
		current = current->next;
	}//need to build test case for this

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
    list.cycleCheck();
    list.findMiddleNode(list.head);
    list.addLastNode(7);
    list.inOrderPrint(list.head);
    //list.reverseList(list.head);
    //list.reversePrint(list.head);

    return 0;
}

