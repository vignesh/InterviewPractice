#include<iostream>
#include<queue>
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
        if(temp->left != NULL) {
            q.push(temp->left);
        }
        if(temp->right != NULL) {
            q.push(temp->right);
        }
        q.pop();
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

int bottomView(Node *root) { 
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
}//wrong, need to fix this! 

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

int pathSum() {

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

int deleteAllLeaves(){

}

int binaryTreeBalanced() {

}

int flattenBinaryTree() {

}

int constructFromPreOrder() {

}

int constructFromLevelOrder() {

}

int checkIfBinaryTree() {

}
 
int main()
{
    Node *root        = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    levelOrder(root);
    //cout << treeDepth(root) << endl;
    //cout << fullBinaryTree(root) << endl;
    //postOrder(root);
    //preOrder(root);
    //inOrder(root);
    return 0;
}