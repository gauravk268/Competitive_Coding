#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl


// #define ENABLE_DEBUG


void solve()
{
    string S, T; 
    getline(cin, S); 
  
    stringstream X(S); 
  
    string pattern="not";
    while (getline(X, T, ' ')) { 
        if(T == pattern)
        {
            cout<<"Real Fancy\n";
            return;
        }
    } 
    
    cout<<"regularly fancy\n";
    
    // cout<<input<<endl;
    return;
}


int main() 
{
    #ifdef ENABLE_DEBUG
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t=1;
	cin>>t;

    string temp;
    getline(cin, temp);
	while(t--)
	{
	    solve();
	}
	
	return 0;
}