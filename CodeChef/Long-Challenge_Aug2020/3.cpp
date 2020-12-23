#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

#define ENABLE_DEBUG


void solve(ll chef, ll rick)
{
    if(chef<=9 && rick<=9)
    {
        cout<<1<<" "<<1<<endl;
        return;
    }
    
    int chefScore, rickScore;
    chefScore = (chef%9)?((chef/9)+1):(chef/9);
    rickScore = (rick%9)?((rick/9)+1):(rick/9);
    
    if(chefScore>=rickScore)
    {
        cout<<1<<" "<<rickScore<<endl;
        return;
    }
    else
    {
        cout<<0<<" "<<chefScore<<endl;
        return;
    }
}


void takeInput()
{
    ll chef, rick;
    cin>>chef>>rick;
    
    solve(chef, rick);
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