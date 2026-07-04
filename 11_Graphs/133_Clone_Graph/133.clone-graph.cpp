/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, unordered_set<Node*>> links;
    unordered_map<Node*, Node*> mapping;
public:
    Node* cloneGraph(Node* node) {
        Node* newNode = new Node();
        newNode->val = node->val;

        mapping[node] = newNode;
        
        for (Node* n : node->neighbors) {
            if (!links[node].count(n)) {
                if (mapping.count(n)) {
                    newNode->neighbors.push_back(mapping[n]);
                }
                else {
                    newNode->neighbors.push_back(cloneGraph(n));
                }
                links[node].insert(n);
            }
        }

       return newNode;
    }
};
// @lc code=end

