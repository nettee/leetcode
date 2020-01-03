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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        int N;
        ListNode* tail;
        get_len_and_tail(head, N, tail);
        k %= N;
        if (k == 0) {
            return head;
        }
        ListNode* q = head;
        ListNode* prev = nullptr;
        for (int i = 0; i < N-k; i++) {
            prev = q;
            q = q->next;
        }
        prev->next = nullptr;
        tail->next = head;
        return q;
    }
    
    void get_len_and_tail(ListNode* head, int& len, ListNode*& tail) {
        int count = 0;
        ListNode* q = head;
        ListNode* prev = nullptr;
        while (q != nullptr) {
            count++;
            prev = q;
            q = q->next;
        }
        len = count;
        tail = prev;
    }
};
