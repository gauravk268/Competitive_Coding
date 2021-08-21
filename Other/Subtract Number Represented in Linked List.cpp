#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
};

Node *newNode(int data)
{
  Node *temp = new Node;
  temp->data = data;
  temp->next = NULL;
  return temp;
}

Node *reverseLL(Node *head)
{
  cerr << "rStart";

  if (head == NULL)
    return NULL;
  struct Node *cur = head, *pre = NULL;

  while (cur != NULL)
  {
    cerr << ".";
    struct Node *t1 = cur->next;
    cur->next = pre;
    pre = cur;
    cur = t1;
  }

  cerr << "rEnd\n";
  return pre;
}

Node *sub(Node *head1, Node *head2)
{
  if (head1 == NULL || head2 == NULL)
    return head1;

  head1 = reverseLL(head1);
  head2 = reverseLL(head2);

  Node *h1 = head1, *h2 = head2;
  int carry = 0;
  
  while (h1 != NULL && h2 != NULL)
  {
    h1->data += carry%10;
    carry /= 10;

    if (h1->data >= h2->data)
    {
      h1->data -= h2->data;
    }
    else
    {
      Node *tmp = h1->next;
      int k = 1;

      while (tmp!=NULL && tmp->data == 0)
      {
        tmp = tmp->next;
        k++;
      }

      if (tmp == NULL)
        return NULL;

      tmp->data -= 1;

      h1->data = (pow(10, k) + h1->data) - h2->data;
    }

    if(h1->data > 9){
      carry += h1->data/10;
      h1->data %= 10;
    }

    h1 = h1->next;
    h2 = h2->next;
  }

  while(carry)
  {
    if(h1->next)
    {
      h1->data += carry%10;
      h1=h1->next;
      carry/=10;
    }
    else
    {
      h1->next = newNode(carry%10);
      carry/=10;
      h1 = h1->next;
    }
  }

  head1 = reverseLL(head1);
  while(head1->data == 0) head1=head1->next;

  return head1;
}

void printList(Node *k)
{
  while (k != NULL)
  {
    cout << k->data << " ";
    k = k->next;
  }
  cout << endl;
}

int main()
{
  Node *head1 = newNode(1);
  head1->next = newNode(0);
  head1->next->next = newNode(0);

  Node *head2 = newNode(99);

  printList(head1);
  printList(head2);

  Node *result = sub(head1, head2);
  printList(result);

  return 0;
}