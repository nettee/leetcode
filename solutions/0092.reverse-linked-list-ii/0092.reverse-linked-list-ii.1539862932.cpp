/*
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (32.73%)
 * Total Accepted:    159.3K
 * Total Submissions: 486.8K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* g = NULL;
        ListNode* h = head;
        for (int i = 0; i < m - 1; i++) {
            g = h;
            h = h->next;
        }
        // h is at position m
        int len = n - m + 1;
        ListNode* prev = NULL;
        ListNode* p = h;
        for (int i = 0; i < len; i++) {
            ListNode* q = p->next;
            p->next = prev;
            prev = p;
            p = q;
        }
        if (g == NULL) {
            head = prev;
        } else {
            g->next = prev;
        }
        h->next = p;
        return head;
    }
};

