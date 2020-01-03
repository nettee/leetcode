/*
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (49.72%)
 * Total Accepted:    425.7K
 * Total Submissions: 856.3K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
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
    ListNode* reverseList(ListNode* head) {
        ListNode* root = NULL;
        for (ListNode* q = head; q != NULL; q = q->next) {
            root = insert(root, q->val);
        }
        return root;
    }

private:
    ListNode* insert(ListNode* root, int val) {
        ListNode* node = new ListNode(val);
        node->next = root;
        return node;
    }
};

