class Solution {    
public:
    ListNode* reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(0), *prev = &dummy;
        
        dummy.next = head;
        for (int i=1; i<m; i++)
            prev = prev->next;
        
        ListNode *pivot = prev->next;
        for (int i=m; i<n; i++) {
            swap(prev->next, pivot->next->next);
            swap(prev->next, pivot->next);
        }
        
        return dummy.next;
    }
};