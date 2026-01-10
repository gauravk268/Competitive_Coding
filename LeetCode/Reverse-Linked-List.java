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
12    public ListNode reverseList(ListNode h) {
13        if (h == null || h.next == null)
14            return h;
15
16        ListNode p = h, prev = null;
17        while (p != null) {
18            ListNode temp = p.next;
19            p.next = prev;
20            prev = p;
21            p = temp;
22        }
23        return prev;
24    }
25}