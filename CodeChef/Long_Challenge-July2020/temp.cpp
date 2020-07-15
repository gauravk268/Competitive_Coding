#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define F first
#define S second
#define pb push_back
#define ll long long
#define endl "\n"

const int MOD = 1e9 + 7;
const int SIZE_INT = 16;


void solution(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    set<int> s;
    unordered_map<int,int> tcnt,cnt1,cnt2;
    int min_e = LLONG_MAX;
    for(auto &e : a){
        cin >> e;
        min_e = min(min_e,e);
        s.insert(e);
        tcnt[e]++;
        cnt1[e]++;
    }
    for(auto &e : b){
        cin >> e;
        min_e = min(min_e,e);
        s.insert(e);
        tcnt[e]++;
        cnt2[e]++;
    }
    for(auto it : s) {
        if(tcnt[it] % 2) {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> arr1 , arr2;
    for(auto it : s) 
    {
        int count1 = 0 , count2 = 0;
        if(cnt1.find(it) != cnt1.end())
            count1 = cnt1[it];
        if(cnt2.find(it) != cnt2.end())
            count2 = cnt2[it];

        // cout << it << "->" << count1 << "," << count2 << endl;

        if(count1 > count2)
        {
            int diff = count1 - count2;
            if(diff % 2)
            {
                cout << -1 << endl;
                return;
            }
            for(int i = 0 ; i < diff ; i += 2)
                arr1.pb(it);
        }
        else if(count2 > count1)
        {
            int diff = count2 - count1;
            if(diff % 2)
            {
                cout << -1 << endl;
                return;
            }
            for(int i = 0 ; i < diff ; i += 2)
                arr2.pb(it),arr1.pb(it);
        }
    }
    
    if(sz(arr1) != 2*sz(arr2))
    {
        cout << -1 << endl;
        return;
    }
   
    sort(all(arr1));

    int min_c = 2*min_e;

    int ans1 = 0;
    int i = 0 , j = sz(arr1);
    while(i < j)
    {
        ans1 += min(arr1[i],min_c);
        i++;
        j--;
    }
    cout << ans1 << endl;
}


void solve()
{
    int n;
    cin >> n;

    vector<ll> a, b, values;

    ll temp, costA = 0, costB = 0;

    cin >> temp;
    a.push_back(temp);
    values.push_back(temp);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> temp;

        if (find(a.begin(), a.end(), temp) == a.end())
        {
            a.push_back(temp);
        }
        else if (find(b.begin(), b.end(), temp) == b.end())
        {
            b.push_back(temp);
            costA++;
        }

        auto it = find(values.begin(), values.end(), temp);
        if (it == values.end())
        {
            values.push_back(temp);
        }
        else
        {
            values.erase(it);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> temp;

        if (find(b.begin(), b.end(), temp) == b.end())
        {
            b.push_back(temp);
        }
        else if (find(a.begin(), a.end(), temp) == a.end())
        {
            a.push_back(temp);
            costB++;
        }

        auto it = find(values.begin(), values.end(), temp);
        if (it == values.end())
        {
            values.push_back(temp);
        }
        else
        {
            values.erase(it);
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (values.empty())
    {
        if(costA > costB)
        {
            cout << costA << endl;
        }
        else
        {
            cout << costB << endl;
        }
    }
    else
    {
        cout << "-1" << endl;
    }

    a.clear();
    b.clear();
    values.clear();
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