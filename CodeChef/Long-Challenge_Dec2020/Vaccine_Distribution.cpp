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
    int n, dose;
    cin>>n>>dose;

    int risk=0, nRisk=0;

    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;

        if(temp>=80 || temp<=9)     risk++;
        else    nRisk++;
    }

    if(dose==1)
    {
        cout<<n<<endl;
        return;
    }

    int time=0;
    if(risk)
    {
        if(risk%dose)   time += (risk/dose)+1;
        else            time += (risk/dose);
    }
    if(nRisk)
    {
        if(nRisk%dose)  time += (nRisk/dose)+1;
        else            time += (nRisk/dose);
    }

    cout<<time<<endl;
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
2
10 1
10 20 30 40 50 60 90 80 100 1
5 2
9 80 27 72 79
Example Output
10
3

*/