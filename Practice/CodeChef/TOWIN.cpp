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
    
    vector<ll> score(n);
    ll first=0, second=0;
    
    for(int i=0; i<n; i++)
    {
        cin>>score[i];
    }
    
    sort(score.begin(), score.end(), greater<ll> ());
    
    for(int i=0; i<n; i++)
    {
        if(i==0)    first+=score[i];
        else if(i==1 || i==2)   second+=score[i];
        else if(i%2)    first+=score[i];
        else    second+=score[i];
    }
    
    if(first>second)    cout<<"first";
    else if(second>first)   cout<<"second";
    else cout<<"draw";
    
    cout<<"\n";
    
    return;
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