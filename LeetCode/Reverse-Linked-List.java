/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null)    return head;
        
        ListNode curr=head, pre=null, temp;

        while(curr != null && curr.next != null){
            temp = curr;
            curr = curr.next;
            temp.next = pre;
            pre = temp;
        }

        curr.next = pre;

        return curr;
    }
}