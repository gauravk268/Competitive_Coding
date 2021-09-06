/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
  Node *copyRandomList(Node *head)
  {
    if (head == NULL)
      return NULL;

    Node *p = head;
    while (p != NULL)
    {
      Node *temp = new Node(p->val);
      temp->next = p->next;
      p->next = temp;

      p = temp->next;
    }

    p = head;
    while (p != NULL && p->next != NULL)
    {
      if (p->random != NULL)
        p->next->random = p->random->next;

      if (p->next == NULL)
        p = p->next;
      p = p->next->next;
    }

    p = head;
    Node *root = p->next, *tmp = p->next;
    while (p != NULL && tmp != NULL)
    {
      p->next = p->next->next;

      if (tmp->next)
        tmp->next = tmp->next->next;

      p = p->next;
      tmp = tmp->next;
    }

    return root;
  }
};