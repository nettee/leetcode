/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        while (curr != null) {
            if (prev != null && prev.val == curr.val) {
                ListNode next = curr.next;
                prev.next = next;
                curr = next;
            } else {
                prev = curr;
                curr = curr.next;
            }
        }
        return head;
    }
}
