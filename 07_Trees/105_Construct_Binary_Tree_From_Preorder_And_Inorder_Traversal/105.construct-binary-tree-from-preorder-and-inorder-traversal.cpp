/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
private:
    int i = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* origin = new TreeNode(preorder[0]);
        build(origin, preorder, inorder, 0, inorder.size() - 1);
        return origin;
    }

    TreeNode* build(TreeNode* root, vector<int>& preorder, vector<int>& inorder, int l, int r) {
        // TreeNode* curr = new TreeNode(preorder[i]);
        if (l > r)  {
            return nullptr;
        }

        root->val = preorder[i++];

        auto first = inorder.begin() + l;
        auto last = inorder.begin() + r + 1;
        int mid = find(first, last, preorder[i]) - inorder.begin();

        root->left = build(new TreeNode(), preorder, inorder, l, mid - 1);

        root->right = build(new TreeNode(), preorder, inorder, mid + 1, r);

        return root;
    }
};
// @lc code=end

