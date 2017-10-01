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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int lheight = maxDepth(root->left);
        int rheight = maxDepth(root->right);
        if (rheight > lheight) {
            return rheight + 1;
        }
        else {
            return lheight + 1;
        }
    }
};