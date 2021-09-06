/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *root=new ListNode(), *p;
        p=root;
        
        while(l1!=NULL || l2!=NULL)
        {
            if(l1!=NULL)
            {
                carry+=l1->val;
                l1=l1->next;
            }
            
            if(l2!=NULL)
            {
                carry+=l2->val;
                l2=l2->next;
            }
            
            p->next = new ListNode(carry%10);
            carry/=10;
            p=p->next;
        }
        
        while(carry)
        {
            p->next = new ListNode(carry%10);
            carry/=10;
            p=p->next;
        }
        
        return root->next;
    }
};