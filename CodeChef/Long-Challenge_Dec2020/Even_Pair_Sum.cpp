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
    ll a, b;
    cin>>a>>b;

    ll evenA, evenB, oddA, oddB;
    if(a%2)
    {
        evenA = a/2, oddA=evenA+1;
    }
    else
    {
        evenA = a/2, oddA=evenA;
    }

    if(b%2)
    {
        evenB = b/2, oddB=evenB+1;
    }
    else
    {
        evenB = b/2, oddB=evenB;
    }
    
    cout<< (evenA*evenB) + (oddA*oddB) <<endl;
    // cerr<<"even: "<<evenB<<endl;
}

int main()
{
	// ONLINE_JUDGE;

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
4
1 1
2 3
4 6
8 9
Example Output
1
3
12
36

1 2 3 4 5 6 7 8 9 10
even => even = n/2 & odd = n/2

1 2 3 4 5 6 7 8 9
odd => even = n/2 & odd = n/2 + 1

e + e = e
o + o = e
o + e = o

*/