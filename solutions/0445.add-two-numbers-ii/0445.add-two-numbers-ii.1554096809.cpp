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
        deque<int> ds1;
        deque<int> ds2;
        list2deq(l1, ds1);
        list2deq(l2, ds2);
        ListNode* res = nullptr;
        int carry = 0;
        while (!ds1.empty() || !ds2.empty()) {
            if (ds1.empty()) {
                int d = ds2.back() + carry;
                insert_head(res, d % 10);
                carry = d / 10;
                ds2.pop_back();
            } else if (ds2.empty()) {
                int d = ds1.back() + carry;
                insert_head(res, d % 10);
                carry = d / 10;
                ds1.pop_back();
            } else {
                int d = ds1.back() + ds2.back() + carry;
                insert_head(res, d % 10);
                carry = d / 10;
                ds1.pop_back();
                ds2.pop_back();
            }
        }
        if (carry > 0) {
            insert_head(res, carry);
        }
        return res;
    }
    
    void list2deq(ListNode* head, deque<int>& out) {
        for (ListNode* q = head; q != nullptr; q = q->next) {
            out.push_back(q->val);
        }
    }
    
    void insert_head(ListNode*& head, int val) {
        ListNode* node = new ListNode(val);
        node->next = head;
        head = node;
    }
};
