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
        ListNode* prev = nullptr;
        ListNode* i = head;
        while (i != nullptr) {
            ListNode* j = i;
            int count = 0;
            while (j != nullptr && j->val == i->val) {
                j = j->next;
                count++;
            }
            if (count > 1) {
                if (prev == nullptr) {
                    head = j;                
                } else {
                    prev->next = j;
                }
                i = j;
            } else {
                // j = i->next
                prev = i;
                i = j;
            }
        }
        return head;
    }
};
