#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

#define ENABLE_DEBUG


int solve(ll H, ll P)
{
    if(P >= H)  return 1;
    
    ll sum=P;
    while(P)
    {
        P=P/2;
        sum += P;
    }
    
    
    if(sum>=H)  return 1;
    return 0;
}


void takeInput()
{
    long long H, P;
    cin>>H>>P;
    
    cout<<solve(H, P)<<"\n";
    return;
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