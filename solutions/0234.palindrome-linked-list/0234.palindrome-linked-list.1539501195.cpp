/*
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (34.30%)
 * Total Accepted:    196.4K
 * Total Submissions: 572.6K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        ListNode* middle = findMiddle(head);
        ListNode* head2 = reverse(middle);
        while (head != NULL && head2 != NULL) {
            if (head == head2) {
                break;
            }
            if (head->val != head2->val) {
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }

private:
    ListNode* findMiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* p = head;
        while (p != NULL) {
            ListNode* q = p->next;
            p->next = prev;
            prev = p;
            p = q;
        }
        return prev;
    }
};

