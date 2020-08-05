#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

#define ENABLE_DEBUG

class node{
    public:
        int value;
        node *lChild, *rChild;
        
        node(){ value=0; lChild=NULL; rChild=NULL; }
        node(int data){ value=data; lChild=NULL; rChild=NULL; }
};


void insert(int data, node *root)
{
    if(root == NULL)
    {
        cout<<"test ";
        root = new node(data);
        return;
    }
    
    while(true)
    {
        if(data < root->value)
        {
            if(root->lChild == NULL)
            {
                root->lChild = new node(data);
                return;
            }
            else{
                root = root->lChild;
                return;
            }
        }
        else
        {
            if(root->rChild == NULL)
            {
                root->rChild = new node(data);
                return;
            }
            else
            {
                root = root->rChild;
                return;
            }
        }
    }
}


void display(node *root)
{
    if(root==NULL)
        return;
    
    display(root->lChild);
    display(root->rChild);
    cout<<root->value<<" ";
}


void solve()
{
    node *root=new node(1);
    
    root->lChild = new node(2*2);
    root->rChild = new node(3*3);
    
    root->lChild->lChild = new node(4*4);
    root->lChild->rChild = new node(5*5);
    root->rChild->lChild = new node(6*6);
    root->rChild->rChild = new node(7*7);
    
    display(root);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t=1;
// 	cin>>t;

	while(t--)
	{
	    solve();
	}
	
	return 0;
}