#include<iostream>
using namespace std;
 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data  = data;
    temp->left  = NULL;
    temp->right = NULL;
    return (temp);
}

int treeDepth(Node *root) {

	if (root == NULL) {
		return 0;
	}

	else if (root->left == NULL && root->right == NULL) {
		return 1;
	}

	else if (root->right != NULL) {
		return treeDepth(root->right) + 1;
	}

	else {
		return treeDepth(root->left) + 1;
	}
	return 0;
}
 
int main()
{
    Node *root        = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    cout << treeDepth(root);
    return 0;
}