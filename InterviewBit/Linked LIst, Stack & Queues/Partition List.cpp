/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


ListNode* Solution::partition(ListNode* A, int x) {
   ListNode *left = new ListNode(0), *right = new ListNode(0);
   
   ListNode *lr=left, *rr=right;
   while(A!=NULL){
       if(A->val < x){
           lr->next = new ListNode(A->val);
           lr=lr->next;
       }else{
           rr->next = new ListNode(A->val);
           rr=rr->next;
       }
       
       A=A->next;
   }
   
   right=right->next;
   lr->next=right;
   
   return left->next;
}
