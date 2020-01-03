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
        ListNode* prev = nullptr;
        ListNode* p = head;
        while (p != nullptr) {
            ListNode* p_next = p->next;
            p->next = prev;
            prev = p;
            p = p_next;
        }
        return prev;
    }
};
