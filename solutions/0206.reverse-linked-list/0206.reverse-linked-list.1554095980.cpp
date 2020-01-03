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
        ListNode* q = head;
        ListNode* prev = nullptr;
        while (q != nullptr) {
            ListNode* q_next = q->next;
            q->next = prev;
            prev = q;
            q = q_next;
        }
        return prev;
    }
};
