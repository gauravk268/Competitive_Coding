/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode *slow=A, *fast=A;

    B++;
    while(B-- && fast!=NULL){
        fast=fast->next;
    }

    if(fast==NULL || fast==slow)  return A->next;
    
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }

    slow->next = slow->next->next;

    return A;
}
