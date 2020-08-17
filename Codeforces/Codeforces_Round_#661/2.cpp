#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

#define ENABLE_DEBUG


void solve( vector<long long> &candies, vector<long long> &oranges, ll minCandies, ll minOranges)
{
    int n=candies.size();
    
    ll result=0;
    
    for(int i=0; i<n; i++)
    {
        candies[i] -= minCandies;
        oranges[i] -= minOranges;
        
        if(candies[i] && oranges[i])
        {
            result += min(candies[i], oranges[i]);
            result += abs(candies[i] - oranges[i]);
        }
        else if(candies[i])
        {
            result += candies[i];
        }
        else if(oranges[i])
        {
            result += oranges[i];
        }
    }
    
    cout<<result<<"\n";
}


void takeInput()
{
    int n;
    cin>>n;
    
    vector<long long> candies(n), oranges(n);
    ll minOranges=MOD, minCandies=MOD;
    
    for(int i=0; i<n; i++){
        cin>>candies[i];
        
        if(candies[i] < minCandies)     minCandies=candies[i];
    }
        
    for(int i=0; i<n; i++){
        cin>>oranges[i];
        
        if(oranges[i] < minOranges)     minOranges=oranges[i];
    }
        
    solve(candies, oranges, minCandies, minOranges);
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