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
ListNode* reverseLL(ListNode* l1){
    ListNode *cur=l1, *pre=NULL;
    
    while(cur){
        ListNode *temp=cur;
        cur=cur->next;
        
        temp->next=pre;
        pre=temp;
    }
    
    return pre;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)    return l2;
        if(l2==NULL)    return l1;
        
        l1=reverseLL(l1);
        l2=reverseLL(l2);
        
        ListNode *result=new ListNode;
        ListNode *temp=result;
        int carry=0;
        while(l1 && l2){
            carry = carry + l1->val + l2->val;
            
            temp->next = new ListNode;
            temp=temp->next;
            temp->val = carry%10;
            carry/=10;
            
            l1=l1->next;
            l2=l2->next;
        }
        
        while(l1){
            carry = carry + l1->val;
            
            temp->next = new ListNode;
            temp=temp->next;
            temp->val = carry%10;
            carry/=10;
            
            l1=l1->next;
        }
        
        while(l2){
            carry = carry + l2->val;
            
            temp->next = new ListNode;
            temp=temp->next;
            temp->val = carry%10;
            carry/=10;
            
            l2=l2->next;
        }
        
        while(carry){
            temp->next = new ListNode;
            temp=temp->next;
            temp->val = carry%10;
            carry/=10;
        }
        
        result = result->next;
        result = reverseLL(result);
        return result;
    }
};
