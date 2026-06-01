/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    struct CompareNode {
        bool operator()(const ListNode* a, const ListNode* b) {
            if (!a && !b) return false;
            if (!a) return true;
            if (!b) return false;

            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> pq;
        
        for (list : lists) {
            pq.push(list);
        }

        


    }
};
// @lc code=end

