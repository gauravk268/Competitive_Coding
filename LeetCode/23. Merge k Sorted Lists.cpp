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
  ListNode *lastNode(ListNode *root)
  {
    if (root == NULL)
      return NULL;
    while (root->next != NULL)
      root = root->next;

    return root;
  }

  ListNode *mergeLL(ListNode *a, ListNode *b)
  {
    ListNode *root = new ListNode(), *p = root;

    while (a != NULL && b != NULL)
    {
      if (a->val <= b->val)
      {
        p->next = new ListNode(a->val);
        a = a->next;
      }
      else
      {
        p->next = new ListNode(b->val);
        b = b->next;
      }

      p = p->next;
    }

    while (a != NULL)
    {
      p->next = new ListNode(a->val);
      a = a->next;

      p = p->next;
    }

    while (b != NULL)
    {
      p->next = new ListNode(b->val);
      b = b->next;

      p = p->next;
    }

    return root->next;
  }

  ListNode *mergeSortLL(ListNode *a)
  {

    if (a == NULL || a->next == NULL)
      return a;

    ListNode *fast = a, *slow = a, *pre = NULL;

    while (fast != NULL && fast->next != NULL)
    {
      pre = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    pre->next = NULL;

    ListNode *left = mergeSortLL(a), *right = mergeSortLL(slow);
    return mergeLL(left, right);
  }

  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    if (lists.size() == 0)
      return NULL;
    ListNode *root = new ListNode(), *p = root;

    for (int i = 0; i < lists.size(); i++)
    {
      if (lists[i] != NULL)
      {
        p->next = lists[i];
        ListNode *tmp = lastNode(p);
        if (tmp != NULL)
          p = tmp;
      }
    }

    return mergeSortLL(root->next);
  }
};