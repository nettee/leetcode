/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (41.99%)
 * Total Accepted:    364.8K
 * Total Submissions: 868.8K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* i = l1;
        ListNode* j = l2;

        while (i != NULL || j != NULL) {
            if (i == NULL) {
                insert(j->val);
                j = j->next;
            } else if (j == NULL) {
                insert(i->val);
                i = i->next;
            } else if (i->val < j->val) {
                insert(i->val);
                i = i->next;
            } else {
                insert(j->val);
                j = j->next;
            }
        }

        return r;
    }
private:
    ListNode* r = NULL;
    ListNode* last = NULL;

    void insert(int val) {
        ListNode* n = new ListNode(val);
        if (last == NULL) {
            r = n;
            last = n;
        } else {
            last->next = n;
            last = n;
        }
    }
};

