/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    stack<int> s;
    ListNode* k=A;
    while(k!=NULL){
        s.push(k->val);
        k=k->next;
    }

    k=A;
    while(k!=NULL){
        int tmp=s.top();    s.pop();
        if(k->val != tmp)   return false;
        k=k->next;
    }

    return true;
}
