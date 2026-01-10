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
12    public ListNode reverse(ListNode h) {
13        if (h == null || h.next == null) {
14            return h;
15        }
16
17        ListNode p = h, prev = null;
18        while (p != null) {
19            ListNode temp = p.next;
20            p.next = prev;
21            prev = p;
22            p = temp;
23        }
24
25        return prev;
26    }
27
28    public ListNode half(ListNode h) {
29        if (h == null || h.next == null) {
30            return h;
31        }
32
33        ListNode s = h, f = h, prev = null;
34        while (f != null && f.next != null) {
35            s = s.next;
36            f = f.next.next;
37        }
38
39        return s;
40    }
41
42    public int pairSum(ListNode head) {
43        ListNode p = head, h = reverse(half(head));
44
45        int result = 0;
46
47        ListNode a = p, b = h;
48        while (p != null && h != null) {
49
50            result = Math.max(result, p.val + h.val);
51            p = p.next;
52            h = h.next;
53        }
54
55        return result;
56    }
57}