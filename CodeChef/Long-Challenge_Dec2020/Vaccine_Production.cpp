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
    int d1, d2, v1, v2, p;
    cin>>d1>>v1>>d2>>v2>>p;

    int time=0;
    if(d1 == d2)
    {
        int cap = v1+v2;

        if(p%cap)       time = (p/cap)+1;
        else            time = p/cap;
    }
    else
    {
        if(d1 < d2)
        {
            if(v1*(d2-d1)>=p)
            {
                if(p%v1)    time = (p/v1)+1;
                else        time = (p/v1);
            }
            else
            {
                p -= v1*(d2-d1);
                int cap = v1+v2;

                if(p%cap)   time = (p/cap)+1+(d2-d1);
                else        time = (p/cap) + (d2-d1);
            }            
        }
        else
        {
            if(v2*(d1-d2)>=p)
            {
                if(p%v2)   time = (p/v2)+1;
                else        time = (p/v2);
            }
            else
            {
                p -= v2*(d1-d2);
                int cap = v1+v2;

                if(p%cap)   time = (p/cap)+1+(d1-d2);
                else        time = (p/cap)+(d1-d2);
            }
        }
    }
    
    if(min(d1, d2)!=1)        cout<<time+min(d1, d2)-1<<endl;
    else                      cout<<time<<endl;
}

int main()
{
	// ONLINE_JUDGE;

    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solution();
    }

    showRunTime;
    return 0;
}

/*

Example Input 1
1 2 1 3 14
Example Output 1
3

Example Input 2
5 4 2 10 100
Example Output 2
9

*/