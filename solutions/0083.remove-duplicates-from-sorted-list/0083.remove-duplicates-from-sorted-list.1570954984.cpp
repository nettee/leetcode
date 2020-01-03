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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while (cur != nullptr) {
            if (prev != nullptr && cur->val == prev->val) {
                ListNode* next = cur->next;
                prev->next = next;
                cur = next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
