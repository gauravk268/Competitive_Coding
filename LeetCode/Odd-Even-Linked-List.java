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
12    public ListNode oddEvenList(ListNode h) {
13        if (h == null || h.next == null)
14            return h;
15
16        ListNode odd = h, a = odd;
17        ListNode even = h.next, b = even;
18        h = h.next.next;
19
20        int i = 3;
21        while (h != null) {
22            if (i % 2 == 1) {
23                a.next = h;
24                a = a.next;
25            } else {
26                b.next = h;
27                b = b.next;
28            }
29            i++;
30            h = h.next;
31        }
32
33        a.next = even;
34        b.next = null;
35
36        return odd;
37    }
38}