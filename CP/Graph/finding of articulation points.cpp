#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define f first
#define ll long long int
#define REP(i,k,n) for(int i=k;i<n;i++)
#define s second
#define pb push_back
#define vi vector<int>
#define mp make_pair
#define  pii  pair<int,int>
#define fast ios::sync_with_stdio(false);cin.tie(0);
#define maxl 100005
//So ultimately it all converges down to finding a back edge for every vertex.
//So, for that apply a DFS and record the discovery time of every vertex and
// maintain for every vertex  the earliest discovered vertex that can be reached from any of the vertices in the subtree rooted at .
//If a vertex  is having a child  such that the earliest discovered vertex that can be reached from the vertices in the subtree rooted at  has a discovery time greater than or equal to , then  does not have a back edge, and thus  will be an articulation point.

//So, till now the algorithm says that if all children of a vertex  are having a back edge, then  is not an articulation point. But what will happen when  is root of the tree, as root does not have any ancestors.
// Well, it is very easy to check if the root is an articulation point or not.
//If root has more than one child than it is an articulation point otherwise it is not.
// Now how does that help?? Suppose root has two children,  and .
//If there had been an edge between vertices in the subtree rooted at  and those of the subtree rooted at , then they would have been a part of the same subtree.
 //vertex, count children. If currently visited vertex u is root (parent[u] is NIL) and has more than two children, print it.
//How to handle second case? The second case is trickier. We maintain an array disc[] to store discovery time of vertices. For every node u, we need to find out the earliest visited vertex (the vertex with minimum discovery time) that can be reached from subtree rooted with u. So we maintain an additional array low[] which is defined as follows.


 bool vis[maxl];
    bool ap[maxl];
vi v[maxl];
int parent[maxl];
int disc[maxl]; //discovery time it will store the time they will be find in dfs tree (it will be unique)
int low[maxl];  //it will hold lowest(upppermost) ancestor one can go by using only one back edge(multiple normal edges) in dfs tree
int timer=0;
void dfs(int idx)
{
   vis[vert]=true;
    disc[vert]=low[vert]=++timer;
    int cntchild=0;
    for(int i=0;i<v[vert].size();i++)
    {
        int child=v[vert][i];
        if(vis[child]==false)
        {
            cntchild++;
            parent[child]=vert;
            dfs(child);
            low[vert]=min(low[vert],low[child]);
            if(cntchild>1&&parent[vert]==-1)
            ap[vert]=true;
            if(parent[vert]!=-1&&low[child]>=disc[vert])
            ap[vert]=true;
        }
        else
        {
            if(parent[vert]!=-1)
            low[vert]=min(low[vert],disc[child]);
        }
    }

}
void calap(int n)
{
   REP(i,0,n+1)
   {
       ap[i]=false;
       vis[i]=false;
       parent[i]=-1;
       disc[i]=0;
       low[i]=INT_MAX;

   }
   	REP(i,1,n+1)
	{
	    if(!vis[i])
	    dfs(i);
	}
   int cnt=0;
   REP(i,1,n+1)
   if(ap[i])
   cout<<i<<" ";


}
int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;

	REP(i,0,m)
	{
	    int x,y;
	    cin>>x>>y;
	    v[x].pb(y);
	    v[y].pb(x);
	}
	calap(n);

	return 0;
}
