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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while (fast != nullptr) {
            fast = fast->next;
            prev = cur;
            cur = cur->next;
        }
        
        // remove cur
        if (prev == nullptr) {
            ListNode* q = cur;
            ListNode* newHead = cur->next;
            delete cur;
            return newHead;
        } else {
            prev->next = cur->next;
            delete cur;
            return head;
        }
    }
};
