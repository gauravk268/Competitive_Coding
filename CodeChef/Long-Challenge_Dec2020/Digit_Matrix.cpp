#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define endl     "\n"
#define dotl     " "
#define MOD      1000000007
#define deb(x)   cout<<#x<<"="<<x<<endl
#define showRunTime  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE freopen("input.txt", "r", stdin);    
// freopen("output.txt", "w", stdout);

#define f  first
#define s  second
#define pb push_back
#define pii pair<int, int>
#define mp make_pair

void solution()
{
    int n;
    cin>>n;

    vector<vector<int>> grid(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
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

Example Input
2
12 16
24 28
Example Output
123
456
789

*/