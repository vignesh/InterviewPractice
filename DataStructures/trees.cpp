#include <iostream>
#include <queue>
#include <stack>
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

int preOrder(Node *root) {
	if (root == NULL) {
		return 0;
	}
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
	return 0;
}

int postOrder(Node* root) {
	if (root == NULL) {
		return 0;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data <<  " ";
	return 0;
}

int inOrder (Node *root) {
	if (root == NULL) {
		return 0;
	}
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
	return 0;
}

int levelOrder (Node *root) {
	queue<Node *> q;
    if (root != NULL) {
        q.push(root);
    }
    while (!q.empty()) {
        Node *temp =q.front();
        cout << temp->data << " ";
        q.pop();
        if(temp->left != NULL) {
            q.push(temp->left);
        }
        if(temp->right != NULL) {
            q.push(temp->right);
        }
    }
}

int height(Node *root) {
	if (root == NULL) {
		return 0;
	}
	int lheight = height(root->left);
	int rheight = height(root->right);
	if (rheight > lheight) {
		return(rheight+1);
	}
	else {
		return (lheight+1);
	}
}

int printLevel(Node * root, int level) {
	if (root == NULL) {
		return 0;
	}
	if (level == 1) {
		printf("%d ", root->data);
	}
	else if (level > 1) {
		printLevel(root->left, level -1);
		printLevel(root->right, level -1);
	}
}

int levelOrder2(Node *root) {
	int h =  height(root);
	for (int i = 1; i <= h; i++) {
		printLevel(root, i);
	}
}

Node* insertBST(Node *root, int value) {
	if (root == NULL) {
		newNode(value);
		return root;
	}
	if (root->data < value) {
		root->right = insertBST(root->right, value);
	}
	if(root->data > value) {
		root->left = insertBST(root->left, value);
	}
	return root;
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

int sum = 0;
int maxSumBST(Node *root) {
	if (root == NULL) {
		return sum;
	}
	if (root->data) {
		sum += root->data;
		return maxSumBST(root->right);
	}
}

bool fullBinaryTree(Node *root) {
	if (root == NULL) {
		return true;
	}
	if (root->right == NULL && root->left == NULL) {
		return true;
	}
	if (root->right != NULL && root->right != NULL) {
		return (fullBinaryTree(root->right) && fullBinaryTree(root->left));
	}
	return false;
}

/*int bottomView(Node *root) { 
	if (root == NULL) {
		return 0;
	}
	if (root->right != NULL && root->left != NULL) {
		cout << root->data;
	}
	if (root->right != NULL) {
		bottomView(root->right);
	}
	if (root->left != NULL) {
		bottomView(root->left);
	}
	return 0;
}//wrong, need to fix this! */

int topView(Node *root) {
	if (root->left) {
        root->left->right = NULL;
        topView(root->left);
    }
    cout << root->data << " ";
    if (root->right) {
        root->right->left = NULL;
        topView(root->right);
    }
}

Node* lowestCommonAncestorBST(Node *root, int value1, int value2) {
	if (root == NULL) {
		return 0;
	}
	if (root->data > value1 && root->data > value2) {
		root = lowestCommonAncestorBST(root->right, value1, value2);
	}
	if (root->data < value1 && root->data < value2) {
		root = lowestCommonAncestorBST(root->left, value1, value2);
	}
	return root;
}

Node* mirror(Node *root) {
	if (root == NULL) {
		return 0;
	}
	Node *newNode = new Node;
	newNode->data = root->data;
	newNode->left = mirror(root->left);
	newNode->right = mirror(root->right);
	return root;
}

void zigzag (Node * root) { //spiral
	stack <Node*> s;
	stack <Node*> s2;
	if (root != NULL) {
		s.push(root);
	}
	while (!s.empty() || !s2.empty()) {
		while(!s.empty()) {
			Node *temp =  s.top();
			s.pop();
			cout << temp->data << " ";
			if (temp->right) {
				s2.push(temp->right);
			}
			if (temp->left) {
				s2.push(temp->left);
			}
		}
		while(!s2.empty()) {
			Node *temp =  s2.top();
			s2.pop();
			cout << temp->data << " ";
			if (temp->left) {
				s.push(temp->left);
			}
			if (temp->right) {
				s.push(temp->right);
			}
		}
	}
}

int pathSum() {

}

int printLeastToGreatest() {

}

int deleteAllLeaves(){

}

int binaryTreeBalanced() {

}

int flattenBinaryTree() {

}

int constructFromArray() {

}

int checkIfBinaryTree() {

}
 
int main()
{
    Node *root        = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    /*root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);*/
    //levelOrder(root);
    //levelOrder2(root);
    //height(root);
    //topView(root);
    zigzag(root);
    //cout << treeDepth(root) << endl;
    //cout << fullBinaryTree(root) << endl;
    //postOrder(root);
    //preOrder(root);
    //inOrder(root);
    return 0;
}