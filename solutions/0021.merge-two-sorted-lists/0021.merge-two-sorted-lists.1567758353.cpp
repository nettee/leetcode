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
        
        ListNode* q1 = l1;
        ListNode* q2 = l2;
        while (q1 != nullptr || q2 != nullptr) {
            if (q1 == nullptr) {
                append(head, tail, q2->val);
                q2 = q2->next;
            } else if (q2 == nullptr) {
                append(head, tail, q1->val);
                q1 = q1->next;
            } else if (q1->val < q2->val) {
                append(head, tail, q1->val);
                q1 = q1->next;
            } else {
                append(head, tail, q2->val);
                q2 = q2->next;
            }
        }
        return head;
    }
    
    void append(ListNode*& head, ListNode*& tail, int val) {
        ListNode* node = new ListNode(val);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
};
