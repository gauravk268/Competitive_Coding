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
13        if(h==null || h.next == null)   return h;
14
15        ListNode p=h, prev=null;
16        while(p!=null){
17            ListNode temp = p;
18            p = p.next;
19            temp.next = prev;
20            prev = temp;
21        }
22        return prev;
23    }
24}