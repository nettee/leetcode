/*
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (34.31%)
 * Total Accepted:    180.2K
 * Total Submissions: 525.4K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example:
 * 
 * 
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = NULL;
        ListNode* q = head;
        while (q != NULL) {
            if (q->val == val) {
                if (prev == NULL) {
                    head = q->next;
                } else {
                    prev->next = q->next;
                }
                ListNode* t = q;
                q = q->next;
                delete t;
            } else {
                prev = q;
                q = q->next;
            }
        }
        return head;
    }
};

