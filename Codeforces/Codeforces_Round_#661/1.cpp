#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

#define ENABLE_DEBUG


void solve( vector<int> &input )
{
    int n=input.size();
    vector<int> diff(n);
    
    if(n==1)
    {
        cout<<"YES\n";
        return;
    }
    
    sort(input.begin(), input.end());
    
    diff[0]=0;
    for(int i=1; i<n; i++)
    {
        diff[i]=input[i]-input[i-1];
    }
    
    sort(diff.begin(), diff.end(), greater<int>());
    
    if(diff[0]>1)  cout<<"NO\n";
    else    cout<<"YES\n";
    
    // for(auto values:input)
    //     cout<<values<<" ";
    // cout<<"\n";
}


void takeInput()
{
    int n;
    cin>>n;
    
    vector<int> input(n);
    for(int i=0; i<n; i++)
        cin>>input[i];
        
    solve(input);
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