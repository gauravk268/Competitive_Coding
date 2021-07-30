/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(A==NULL) return B;
    if(B==NULL) return A;

    ListNode *root, *k;
    root=new ListNode(0);
    k=root;
    while(A!=NULL && B!=NULL){
        if(A->val < B->val){
            root->next = new ListNode(A->val);
            A=A->next;
            root=root->next;
        }else{
            root->next = new ListNode(B->val);
            B=B->next;
            root=root->next;
        }
    }

    while(A!=NULL){
        root->next = new ListNode(A->val);
        A=A->next;
        root=root->next;
    }

    while(B!=NULL){
        root->next = new ListNode(B->val);
        B=B->next;
        root=root->next;
    }

    return k->next;
}
