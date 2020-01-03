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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        
        for (ListNode* l : lists) {
            if (l != nullptr) {
                pq.push(make_pair(l->val, l));
            }
        }
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            append(head, tail, top.first);
            ListNode* node = top.second;
            
            ListNode* next = node->next;
            if (next != nullptr) {
                pq.push(make_pair(next->val, next));
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
