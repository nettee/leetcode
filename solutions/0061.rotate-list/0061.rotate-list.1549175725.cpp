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
        if (head == NULL) {
            return head;
        }
        auto p1 = len(head);
        int N = p1.first;
        ListNode* tail = p1.second;
        k = k % N;
        if (k == 0) {
            return head;
        }
        
        auto p2 = findnth(head, N-k);
        ListNode* prev = p2.first;
        ListNode* q = p2.second;
        
        if (prev == NULL) {
            return q;
        } else {
            prev->next = NULL;
            tail->next = head;
            return q;
        }
    }
    
    // Get length and tail node
    pair<int, ListNode*> len(ListNode* head) {
        int c = 0;
        ListNode* prev = NULL;
        ListNode* q = head;
        while (q != NULL) {
            prev = q;
            q = q->next;
            c++;
        }
        return make_pair(c, prev);
    }
    
    pair<ListNode*, ListNode*> findnth(ListNode* head, int n) {
        ListNode* prev = NULL;
        ListNode* q = head;
        for (int i = 0; i < n; i++) {
            prev = q;
            q = q->next;
        }
        return make_pair(prev, q);
    }
};
