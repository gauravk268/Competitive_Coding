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
    int n;
    cin>>n;
    
    if ( n <= 2 || (n & (n - 1)) == 0)    {cout << -1 << endl;    return;}

    vector<int> result = {2, 3, 1};

    for (int i = 4; i <= n; i++)
    {
        if((i & i-1) == 0)
        {
            if(i<=(n-1))
            {
                result.push_back(i+1);
                result.push_back(i);
                i++;
                continue;
            }
            else
            {
                cout<<-1<<endl;
                return;
            }
        }

        result.push_back(i);
    }

    if(result.size() != n)
    {
        cout<<-1<<endl;
        return;
    }

    for (auto temp : result)
        cout << temp << " ";
    cout<<endl;

    // for(int i=1; i<n; i++)
    //     if((result[i-1]&result[i])==0)   cerr<<"error: "<<n<<endl;
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


*/