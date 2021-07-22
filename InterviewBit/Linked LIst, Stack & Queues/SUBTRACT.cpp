/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::subtract(ListNode* A) {
    vector<int> values;
    ListNode *p=A;
    while(p){
        values.push_back(p->val);
        p=p->next;
    }

    int k=values.size()/2;
    reverse(values.begin(), values.end());

    p=A;
    for(int i=0; i<k; i++){
        p->val = values[i]-p->val;
        p=p->next;
    }

    return A;
}
