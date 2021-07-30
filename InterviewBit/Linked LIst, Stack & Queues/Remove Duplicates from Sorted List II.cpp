/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* fun(ListNode* A, int value){
    if(A==NULL || A->next==NULL)   return A;

    while(A!=NULL && A->val==value) A=A->next;
    return A;
}

ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL || A->next==NULL)   return A;

    ListNode *k=A, *pre=NULL;
    while(k!=NULL && k->val == k->next->val){
        k=fun(k, k->val);
        A=k;
    }

    while(k!=NULL){
        if(k->next != NULL && k->val == k->next->val){
            pre->next=fun(k, k->val);
            k=pre;
        }else{
            pre=k;
            k=k->next;
        }
    }

    return A;
}
