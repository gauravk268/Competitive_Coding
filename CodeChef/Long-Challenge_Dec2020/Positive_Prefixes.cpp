#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define endl     "\n"
#define spa      " "
#define MOD      1000000007
#define deb(x)   cerr<<#x<<"="<<x<<endl
#define showRunTime  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#define f  first
#define s  second
#define pb push_back
#define pii pair<int, int>
#define mp make_pair

int solve(int k, int neg, vector<int> &v, int count, int n)
{
    count++;

    if(count==(n+1) && (neg==0 && k==0))
        return 1;

    v.push_back(count);
    if(accumulate(v.begin(), v.end(), 0) >= 0)
        k--;
    else
        neg--;

    if(solve(k, neg, v, count, n) == 1)
        return 1;
    else
    {
        v.pop_back();
        v.push_back((-1)*count);

        if(accumulate(v.begin(), v.end(), 0) >= 0)
            k--;
        else
            neg--;

        if(solve(k, neg, v, count, n) == 1)
            return 1;
    }

    return -1;   
}

void solution()
{
    int n, k;
    cin>>n>>k;

    int count = n-k, sum=0;
    
    if(n==k)
    {
        for(int i=1; i<=n; i++)
            cout<<i<<spa;
        cout<<endl;
    }
    else if(k==0)
    {
        for(int i=1; i<=n; i++)
            cout<<i*(-1)<<spa;
        cout<<endl;
    }
    else
    {
        int sumF=(n*(n-1))/2, sumB=0;
        int neg = n-k;

        vector<int> result;
        
        if(solve(k, neg, result, 0, n))
        {
            for(int i=0; i<n; i++)
                cout<< result[i]<<spa;
            cout<<endl;
        }
        else
            cout<<"err!!\n"<<endl;
    }
}

int main()
{
	ONLINE_JUDGE;

    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solution();
    }

    showRunTime;
    return 0;
}

/*

Example Input
1
3 3

Example Output
1 2 3

*/