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
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        return treeSum(root, maxPath);
    }
    
    int treeSum(TreeNode *root, int &sum) {
        
        if (root == NULL) {
            return 0;
        }
        
        if (root->right == NULL && root->left == NULL) {
            return root->val;
        }
        
        int left = treeSum(root->left, sum);
        int right = treeSum(root->right, sum);
        
        if (root->left && root->right) {
            sum = max(sum, left + right + root->val);
            return max(left, right) + root->val;
        }
        
        if (root->left == NULL) {
            return right + root->val;
        }
        
        if (root->right == NULL) {
            return left + root->val;
        }
    }
};