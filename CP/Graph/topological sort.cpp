#include<bits/stdc++.h>
using namespace std;
#define lm 1001
vector<int> tos;
stack<int> st;
bool visited[lm];
vector<int> ad[lm]; 
void to(int v)
{
    visited[v]=true;
int i;st.push(v);
for(i=0;i<ad[v].size();i++)
{
    if(visited[ad[v][i]]==true)
    continue;

    to(ad[v][i]);
}
int b=st.top();
tos.push_back(b);
st.pop();
    
}
void topsor(int n)
{int i;
for(i=0;i<=n;i++)
visited[i]=false;
for(i=1;i<=n;i++)
{if(visited[i]==false)
{to(i);}}
int res[tos.size()];
for(i=0;i<tos.size();i++)
res[tos.size()-i-1]=tos[i];
for(i=0;i<tos.size();i++)
cout<<res[i]<<" ";

    
    
}
int main()
{int n,e,m,j,i;
cin>>n>>e;
for(i=0;i<e;i++)
{int x,y;
cin>>x>>y;
ad[x].push_back(y);
}
topsor(n);
    
}