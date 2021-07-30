/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::solve(ListNode* A) {
    int arr[2];
    arr[0]=arr[1]=0;

    ListNode *k=A;
    while(k!=NULL){
        arr[k->val]++;
        k=k->next;
    }

    k=A;
    while(arr[0]){
        k->val=0;
        k=k->next;
        arr[0]--;
    }

    while(arr[1]){
        k->val=1;
        k=k->next;
        arr[1]--;
    }

    return A;
}
