/*
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (34.96%)
 * Total Accepted:    138.6K
 * Total Submissions: 396.4K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * Example:
 * 
 * 
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = NULL;
        ListNode* tail1 = NULL;
        ListNode* head2 = NULL;
        ListNode* tail2 = NULL;
        ListNode* p = head;
        while (p != NULL) {
            ListNode* q = p;
            p = p->next;
            if (q->val < x) {
                append(&head1, &tail1, q);
            } else {
                append(&head2, &tail2, q);
            }
        }
        if (head1 == NULL) {
            return head2;
        } else {
            tail1->next = head2;
            return head1;
        }
    }

private:
    void append(ListNode** pHead, ListNode** pTail, ListNode* x) {
        x->next = NULL;
        if (*pHead == NULL) {
            *pHead = x;
            *pTail = x;
        } else {
            (*pTail)->next = x;
            *pTail = x;
        }
    }
};

