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
  ListNode *reverseLL(ListNode *root)
  {
    if (root == NULL || root->next == NULL)
      return root;

    ListNode *cur = root, *pre = NULL;
    while (cur != NULL)
    {
      ListNode *tmp = cur;
      cur = cur->next;
      tmp->next = pre;
      pre = tmp;
    }
    return pre;
  }

  ListNode *reverseKGroup(ListNode *head, int k)
  {
    if (head == NULL || head->next == NULL || k < 2)
      return head;

    ListNode *cur = head, *pre = NULL;
    int tmpK = k;

    while (cur != NULL && tmpK--)
    {
      pre = cur;
      cur = cur->next;
    }

    if (tmpK > 0)
      return head;

    pre->next = NULL;
    head = reverseLL(head);
    pre = head;
    while (pre->next != NULL)
      pre = pre->next;

    pre->next = reverseKGroup(cur, k);

    return head;
  }
};