
//Final all paths thats sum up to a target amount
void treeSumPath(Node* root, int target) {
	vector<int> path;
	int currentSum = 0;
	printTreeSumPath(root, target, currentSum path);
}

void printTreeSumPath(Node* root, int target, int currentSum, vector<int>&path) {
	
	if (!root) {
		return 0;
	}

	currentSum = currentSum + root->data;
	path.pushback(node->data)

	//print path
	if (target == currentSum) {
		for (int i = 0; i < path.size(); i++) {
			cout << path[i] << " ";
		}
		cout << endl;
	}

	if (root->left) {
		printTreeSumPath(root->left, target, currentSum, path);
	}

	if (root->right) {
		printTreeSumPath(root->right, target, currentSum, path);
	}

	path.pop_back()
}