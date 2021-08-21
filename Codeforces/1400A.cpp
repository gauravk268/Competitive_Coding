#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl


// #define ENABLE_DEBUG


void solve()
{
    int n;
    cin>>n;
    
    string value, result="";
    cin>>value;
    
    for(int i=0; i<value.length(); i+=2)
        result+=value.substr(i,1);
    
    cout<<result<<endl;
    return;
}


void takeInput()
{
    
	
    solve();
    return;
}


int main() {
	#ifdef ENABLE_DEBUG
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif
	
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