/*
 * [908] Middle of the Linked List
 *
 * https://leetcode.com/problems/middle-of-the-linked-list/description/
 *
 * algorithms
 * Easy (62.96%)
 * Total Accepted:    22.4K
 * Total Submissions: 35.6K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given a non-empty, singly linked list with head node head, return a middle
 * node of linked list.
 * 
 * If there are two middle nodes, return the second middle node.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: Node 3 from this list (Serialization: [3,4,5])
 * The returned node has value 3.  (The judge's serialization of this node is
 * [3,4,5]).
 * Note that we returned a ListNode object ans, such that:
 * ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next
 * = NULL.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4,5,6]
 * Output: Node 4 from this list (Serialization: [4,5,6])
 * Since the list has two middle nodes with values 3 and 4, we return the
 * second one.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the given list will be between 1 and 100.
 * 
 * 
 * 
 * 
 */
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
    ListNode* middleNode(ListNode* head) {
       int N = length(head);
       return find(head, N / 2);
    }

private:
    int length(ListNode* head) {
        int count = 0;
        for (ListNode* q = head; q != NULL; q = q->next) {
            count++;
        }
        return count;
    }

    ListNode* find(ListNode* head, int index) {
        ListNode* q = head;
        for (int i = 0; i < index; i++) {
            q = q->next;
        }
        return q;
    }
};

