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
        ListNode* p = l1;
        ListNode* q = l2;
        int c = 0;
        while (p != NULL || q != NULL) {
            int pv = p == NULL ? 0 : p->val;
            int qv = q == NULL ? 0 : q->val;
            int s = pv + qv + c;
            append(s % 10);
            c = s / 10;
            if (p != NULL) p = p->next;
            if (q != NULL) q = q->next; 
        }
        if (c != 0) {
            append(c);
        }
        return head;
    }
    
    void append(int val) {
        if (head == NULL) {
            ListNode* node = new ListNode(val);
            head = node;
            tail = node;
        } else {
            ListNode* node = new ListNode(val);
            tail->next = node;
            tail = node;
        }
    }
    
private:
    ListNode* head = NULL;
    ListNode* tail = NULL;
};
