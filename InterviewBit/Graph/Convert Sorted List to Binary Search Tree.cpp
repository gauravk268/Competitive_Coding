/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode *cur=A, *p=NULL, *fast=A;

    if(A==NULL) return NULL;
    if(A->next==NULL)  return new TreeNode(A->val);

    while(fast!=NULL &&  fast->next !=NULL){
      p=cur;
      cur=cur->next;
      fast=fast->next->next;
    }

    TreeNode* root=new TreeNode(cur->val);
    p->next=NULL;
    root->left=sortedListToBST(A);

    cur=cur->next;
    if(cur!=NULL)   root->right=sortedListToBST(cur);

    return root;
}
