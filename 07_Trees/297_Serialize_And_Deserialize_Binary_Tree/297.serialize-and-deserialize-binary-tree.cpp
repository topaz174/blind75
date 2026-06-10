/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    int idx = 0;

    void helper(TreeNode* root, string& treeStr) {
        if (root == nullptr) {
            treeStr += "n#";
            return;
        }

        treeStr += to_string(root->val) + '#';
        helper(root->left, treeStr);
        helper(root->right, treeStr);
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        helper(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (idx >= data.size()) {
            return nullptr;
        }
        if (data[idx] == 'n') {
            idx += 2;
            return nullptr;
        }

        TreeNode* root = new TreeNode();

        string valStr; 
        while (data[idx] != '#') {
            valStr += data[idx++];
        }
        idx++;

        root->val = stoi(valStr);

        root->left = deserialize(data);
        root->right = deserialize(data);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

