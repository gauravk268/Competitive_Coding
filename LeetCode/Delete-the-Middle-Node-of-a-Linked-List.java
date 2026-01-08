1/**
2 * Definition for singly-linked list.
3 * public class ListNode {
4 *     int val;
5 *     ListNode next;
6 *     ListNode() {}
7 *     ListNode(int val) { this.val = val; }
8 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
9 * }
10 */
11class Solution {
12    public ListNode deleteMiddle(ListNode head) {
13        if(head == null || head.next == null)   return null;
14
15        ListNode slow = head, fast = head, prev = null;
16
17        while (fast != null && fast.next != null) {
18            prev = slow;
19            slow = slow.next;
20            fast = fast.next.next;
21        }
22
23        prev.next = slow.next;
24
25        return head;
26    }
27}