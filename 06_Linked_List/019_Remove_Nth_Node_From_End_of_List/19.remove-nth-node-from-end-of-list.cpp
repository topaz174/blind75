/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* ahead = dummy;
        ListNode* behind = dummy;

        for (int i = 0; i < n && ahead; i++) {
            ahead = ahead->next;
        }

        while (ahead && ahead->next) {
            ahead = ahead->next;
            behind = behind->next;
        }

        ListNode* toRemove = behind->next;
        behind->next = behind->next->next;
        delete toRemove;
        head = dummy->next;
        delete dummy;

        return head;
    }
};
// @lc code=end