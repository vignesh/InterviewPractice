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
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return NULL;
        }
        int middleIndex = (start + end)/2;
        TreeNode* node = new TreeNode(nums[middleIndex]);
        node->left = sortedArrayToBST(nums, start, middleIndex);
        node->right = sortedArrayToBST(nums, middleIndex+1, end);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
};