// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool detectLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        if( detectLoop(head) )
            cout<< "True\n";
        else
            cout<< "False\n";
    }
	return 0;
}
// } Driver Code Ends


/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/

bool detectLoop(Node* head)
{
    Node *slow=head, *fast=head;
    
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast=fast->next->next;
        
        if(slow == fast)    return true;
    }
    
    return false;
}


/*

Input:
3
5
7 58 36 34 16
4
3
1 3 4
2
4
1 8 3 4
0

Output:
True
True
False
*/