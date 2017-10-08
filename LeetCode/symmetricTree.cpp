//Recrusive Solution
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
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
    
    bool isSymmetric(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) {
            return true;
        }
        if (root1 && root2 && root1->val == root2->val) {
            return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
        }
        return false;
    }
};

//Iterative Solution
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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> lq;
        queue<TreeNode*> rq;
        lq.push(root);
        rq.push(root);
        while (!lq.empty() && !rq.empty()) {
            TreeNode* leftNode = lq.front();
            TreeNode* rightNode = rq.front();
            lq.pop();
            rq.pop();
            if (!leftNode && !rightNode) {
                continue;
            }
            if ((leftNode && !rightNode) || (!leftNode && rightNode)) {
                return false;
            }
            if (leftNode->val != rightNode->val) {
                return false;
            }
            lq.push(leftNode->right);
            lq.push(leftNode->left);
            rq.push(rightNode->left);
            rq.push(rightNode->right);
        }
        return true;
    }
};