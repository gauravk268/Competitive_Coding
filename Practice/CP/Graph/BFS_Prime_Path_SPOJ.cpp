#include<bits/stdc++.h>
using namespace std;

vector<int> ar[10001], prime;
int dis[10001], vis[10001];

bool isPrime(int n)
{
    if(n%2 == 0)
        return false;

    for(int i=2; i*i<=n; i++)
    {
        if(n%i == 0)    return false;
    }

    return true;
}

bool isValid(int a, int b)
{
    int count=0;
    while(a && b)
    {
        if(a%10 != b%10)    count++;

        a/=10, b/=10;
    }

    if(count==1)        return true;
    return false;
}


void build_graph()
{
    for(int i=1000; i<10000; i++)
        if(isPrime(i))
            prime.push_back(i);

    for(int i=0; i<prime.size()-1; i++)
    {
        for(int j=i+1; j<prime.size(); j++)
        {
            int a=prime[i];
            int b=prime[j];
            if(isValid(a, b))
                ar[a].push_back(b), ar[b].push_back(a);
        }
    }
}

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    dis[src]=0;
    vis[src]=1;
    
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();

        for(int child:ar[curr])
            if(vis[child]==0)
            {
                q.push(child);
                dis[child]=dis[curr]+1;
                vis[child]=1;
            }
    }
}

int main()
{
    int t, n, m;
    cin>>t;

    build_graph();
    while(t--)
    {
        for(int i=1000; i<10000; i++)   vis[i]=0, dis[i]=-1;
        
        cin>>n>>m;
        bfs(n);
        if(dis[m]== -1) cout<<"IMPOSSIBLE\n";
        else    cout<<dis[m]<<endl;
    }
}

/*
Input:
3
1033 8179
1373 8017
1033 1033

Output:
6
7
0
*/