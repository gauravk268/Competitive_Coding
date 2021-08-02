/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *k=A;
    while(k!=NULL){
        if(k->next != NULL && k->val == k->next->val){
            k->next = k->next->next;
        }else{
            k=k->next;
        }
    }

    return A;
}
