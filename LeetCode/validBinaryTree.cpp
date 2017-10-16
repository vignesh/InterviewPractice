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
    bool isValidBST(TreeNode* root) {
        return validBST(root, NULL, NULL);
    }
    
    bool validBST(TreeNode *root, TreeNode *leftNode, TreeNode *rightNode) {
        if (!root) {
            return true;
        }
        if (leftNode && root->val <= leftNode->val) {
                return false;
        }
        if (rightNode && root->val >= rightNode->val) {
                return false;
        }
        return validBST(root->left, leftNode, root) && validBST(root->right, root, rightNode);
    }
};