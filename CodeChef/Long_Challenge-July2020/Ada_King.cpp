#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

const int MOD = 1e9 + 7;
const int SIZE_INT = 16;

void solve()
{
    int k;
    cin >> k;

    k--;
    bool flag = true;
    int iMark;
    
    if(k==0)
        iMark = 1;

    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            flag = true;
            if (i == 1 && j == 1)
            {
                cout << "O";
                flag = false;
            }

            if (k && flag)
            {
                cout << ".";
                k--;

                if(k==0)
                    iMark = i;

                flag = false;
            }
            
            if(k==0 && flag && i==iMark)
            {
                cout<<"X";
                flag = false;
            }

            if (k == 0 && i==iMark+1)
            {
                cout << "X";
                flag = false;
            }
            
            if(flag)
            {
                cout<<".";
            }
        }

        cout << endl;
    }
}

int main()
{
    //a line to speed-up
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int testCases = 1;
    cin >> testCases; //remove it if only 1 testcase
    while (testCases--)
    {
        solve();
    }

    return 0;
}