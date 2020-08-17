#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

#define ENABLE_DEBUG


int solve(ll k, vector<ll> &chess)
{
    int n=chess.size();
    sort(chess.begin(), chess.end());
    
    return 0;
}


ll GCD(ll a, ll b)
{
    if(b==0)    return a;
    return GCD(b, a%b);
}


void takeInput()
{
    ll n, k;
    cin>>n>>k;
    
    vector<ll> chess;
    while(n--)
    {
        ll temp;
        cin>>temp;
        
        int tempLCM = (k * temp)/GCD(k, temp);
        
        if(tempLCM==k)
            chess.push_back(temp);
    }
    
    if(chess.size()==0)
    {
        cout<<"-1\n";
        return;
    }
    else
    {
        sort(chess.begin(), chess.end(), greater<int>());
        cout<<chess[0]<<"\n";
        return;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t=1;
	cin>>t;

	while(t--)
	{
	    takeInput();
	}
	
	return 0;
}