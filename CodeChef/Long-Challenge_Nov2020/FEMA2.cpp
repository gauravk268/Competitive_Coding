#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define endl     "\n"
#define MOD      1000000007
#define deb(x)   cout<<#x<<"="<<x<<endl
#define showRunTime  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE freopen("input.txt", "r", stdin);    freopen("output.txt", "w", stdout);

#define f  first
#define s  second
#define pb push_back
#define pii pair<int, int>
#define mp make_pair

void solution()
{
    int n, k;
    cin>>n>>k;

    string value;
    cin>>value;

    vector<int> magnets(n), sheets(n);
    int temp[4][n];

    stack<int> max1, max2, min1, min2;

    for(int i=0; i<n; i++)
    {
        if(i==0)
        {
            temp[0][0] = 
        }
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

Input
2
4 5
I::M
9 10
MIM_XII:M

Output
1
2

*/