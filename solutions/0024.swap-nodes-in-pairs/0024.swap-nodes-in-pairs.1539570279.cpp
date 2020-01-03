/*
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (41.10%)
 * Total Accepted:    245.1K
 * Total Submissions: 596.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * Note:
 * 
 * 
 * Your algorithm should use only constant extra space.
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* p = head;
        while (p != NULL && p->next != NULL) {
            ListNode* q = p->next;
            p->next = q->next;
            q->next = p;
            if (prev == NULL) {
                head = q;
            } else {
                prev->next = q;
            }
            prev = p;
            p = p->next;
        }
        return head;
    }
};

