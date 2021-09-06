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
class Solution
{
public:
  ListNode *helperLL(ListNode *root)
  {
    if (root == NULL || root->next == NULL)
      return root;

    ListNode *p = root;
    int k = p->val;
    while (p != NULL && p->val == k)
      p = p->next;

    return p;
  }

  ListNode *deleteDuplicates(ListNode *head)
  {
    if (head == NULL || head->next == NULL)
      return head;

    while (head != NULL && head->next != NULL && head->val == head->next->val)
    {
      head = helperLL(head);
    }

    ListNode *p = head, *pre = NULL;
    while (p != NULL && p->next != NULL)
    {
      if (p->val == p->next->val)
      {
        pre->next = helperLL(p);
        p = pre;
      }
      else
      {
        pre = p;
        p = p->next;
      }
    }

    return head;
  }
};