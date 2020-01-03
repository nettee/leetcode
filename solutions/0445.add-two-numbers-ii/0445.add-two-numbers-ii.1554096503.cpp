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
        reverse_list(l1);
        reverse_list(l2);
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* res = nullptr;
        int carry = 0;
        while (p != nullptr || q != nullptr) {
            if (p == nullptr) {
                int d = q->val + carry;
                insert_head(res, d % 10);
                carry = d / 10;
                q = q->next;
            } else if (q == nullptr) {
                int d = p->val + carry;
                insert_head(res, d % 10);
                carry = d / 10;
                p = p->next;
            } else {
                int d = p->val + q->val + carry;
                insert_head(res, d % 10);
                carry = d / 10;
                p = p->next;
                q = q->next;
            }
        }
        if (carry > 0) {
            insert_head(res, carry);
        }
        return res;
    }
    
    void reverse_list(ListNode*& head) {
        ListNode* q = head;
        ListNode* prev = nullptr;
        while (q != nullptr) {
            ListNode* q_next = q->next;
            q->next = prev;
            prev = q;
            q = q_next;
        }
        head = prev;
    }
    
    void insert_head(ListNode*& head, int val) {
        ListNode* node = new ListNode(val);
        node->next = head;
        head = node;
    }
};
