#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl


#define ENABLE_DEBUG


void solve()
{
    ll n;
    cin>>n;
    
    vector<int> values(n);
    for(int i=0; i<n; i++)
    {
        cin>>values[i];
    }
    
    ll result=0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if((values[i]&values[j]) == values[i])
                result++;
        }
    }
    
    cout<<result<<endl;
}


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t=1;
	cin>>t;

	while(t--)
	{
	    solve();
	}
	
	return 0;
}