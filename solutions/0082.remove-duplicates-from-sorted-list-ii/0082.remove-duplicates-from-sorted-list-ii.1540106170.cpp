/*
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (31.15%)
 * Total Accepted:    153K
 * Total Submissions: 491.3K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* p = head;
        while (p != NULL && p->next != NULL) {
            if (p->val == p->next->val) {
                ListNode* q = p->next;
                while (q != NULL && q->val == p->val) {
                    ListNode* t = q;
                    q = q->next;
                    delete t;
                }
                if (prev == NULL) {
                    head = q;
                } else {
                    prev->next = q;
                }
                p = q;
            } else {
                prev = p;
                p = p->next;
            }
        }
        return head;
    }
};

