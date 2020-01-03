/*
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (33.60%)
 * Total Accepted:    301.3K
 * Total Submissions: 896.8K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* q = head;
        for (int i = 0; i < n; i++) {
            q = q->next;
        }
        ListNode* prev = NULL;
        ListNode* p = head;
        while (q != NULL) {
            q = q->next;
            prev = p;
            p = p->next;
        }
        if (prev == NULL) {
            head = p->next;
            delete p;
        } else {
            ListNode* t = p;
            prev->next = p->next;
            delete t;
        }
        return head;
    }
};

