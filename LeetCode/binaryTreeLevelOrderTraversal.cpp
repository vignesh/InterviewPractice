/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> newLevel;
        queue<TreeNode*> q;
        if (!root) {
            return result;
        }
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode* currentNode = q.front();
            q.pop();
            if (currentNode == NULL) {
                result.push_back(newLevel);
                newLevel.resize(0);
                if (q.size() > 0) {
                    q.push(NULL);
                }
            }
            else {
                newLevel.push_back(currentNode->val);
                if (currentNode->left) {
                    q.push(currentNode->left);
                }
                if (currentNode->right) {
                    q.push(currentNode->right);
                }
            }
        }
        return result;
    }
};