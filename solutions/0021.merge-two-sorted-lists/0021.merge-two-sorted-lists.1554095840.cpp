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
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        ListNode* p = l1;
        ListNode* q = l2;
        while (p != nullptr || q != nullptr) {
            if (p == nullptr) {
                append(head, tail, q->val);
                q = q->next;
            } else if (q == nullptr) {
                append(head, tail, p->val);
                p = p->next;
            } else if (p->val < q->val) {
                append(head, tail, p->val);
                p = p->next;
            } else {
                append(head, tail, q->val);
                q = q->next;
            }
        }
        return head;
    }
    
    void append(ListNode*& head, ListNode*& tail, int val) {
        if (tail == nullptr) {
            ListNode* node = new ListNode(val);
            head = node;
            tail = node;
        } else {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
    }
};
