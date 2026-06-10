/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int count = 0;

        traverse(root, k, ans, count);

        return ans;
    }
    void traverse(TreeNode* root, int k, int& ans, int& count)  {
        if (root == nullptr) {
            return;
        }

        traverse(root->left, k, ans, count);

        count++;

        if (count == k) {
            ans = root->val;
            return;
        }

        traverse(root->right, k, ans, count);
    }
};
// @lc code=end

