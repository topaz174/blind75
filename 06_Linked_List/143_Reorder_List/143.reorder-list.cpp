/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        stack<ListNode*> reversed;
        ListNode* curr = head;
        int size = 0;

        while (curr) {
            reversed.push(curr);

            curr = curr->next;
            size++;
        }

        curr = head;
        ListNode* next = nullptr;

        for (int i = 0; i < size / 2; ++i) {
            next = curr->next;

            curr->next = reversed.top();
            reversed.top()->next = next;

            if (i == size / 2 - 1) {
                next->next = nullptr;
            }

            curr = next;
            reversed.pop();
        }
    }
};
// @lc code=end

