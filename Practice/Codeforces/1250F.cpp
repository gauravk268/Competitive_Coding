#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MOD 1e9+7


bool isRoot(long double x) 
{ 
    long double sr = sqrt(x); 
    return ((sr - floor(sr)) == 0); 
}

void solve()
{
    int n;
    cin>>n;
    
    int ans=(1 * 2) + (n * 2),x;
    for(int i = 1; i <= n/2; i++)
    {
        if(n % i == 0)
        {
            int m = n / i;
            x = i + i + m + m;
            ans = min(ans, x);
        }
    }
    
    cout<<ans<<endl;
}

int main() {
	// your code goes here
	
	int t=1;
// 	cin>>t;

	while(t--)
	{
	    solve();
	}
	
	return 0;
}