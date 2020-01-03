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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        ListNode *q1 = l1, *q2 = l2;
        int carry = 0;
        while (q1 != NULL || q2 != NULL || carry != 0) {
            int d1 = (q1 == NULL) ? 0 : q1->val;
            int d2 = (q2 == NULL) ? 0 : q2->val;
            int d3 = d1 + d2 + carry;
            carry = d3 / 10;
            d3 = d3 % 10;
            ListNode *p = new ListNode(d3);
            tail->next = p;
            tail = p;
            if (q1 != NULL) q1 = q1->next;
            if (q2 != NULL) q2 = q2->next;
        }
        return head->next;
        
    }
};
