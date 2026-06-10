/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int maxLeft = INT_MIN;
        int minRight = INT_MAX;
        return isValidBSTHelper(root, &maxLeft, &minRight);
    }
    bool isValidBSTHelper(TreeNode* curr, int* maxLeft, int* minRight) {
        if (curr == nullptr) {
            return true;
        }
        if (curr->val <= *maxLeft || curr->val >= minRight) {
            return false;
        }

        *maxLeft = max()

        return isValidBSTHelper(curr->right, maxLeft, minRight) &&
            isValidBSTHelper(curr->left, maxLeft, minRight);
    }
};
// @lc code=end

