#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl


#define ENABLE_DEBUG


void powerString(string input, string output)
{
    if(input.length()==0)
    {
        cout<<"[";
        cout<<output;
        cout<<"] ";
        return;
    }
    
    string newInput=input.substr(1);
    string newOutput=output+input.substr(0,1);
    
    
    powerString(newInput, output);
    powerString(newInput, newOutput);
    return;
}


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t=1;
// 	cin>>t;

	while(t--)
	{
	   // solve();
	   
	   string input="ABC", output="";
	   powerString(input, output);
	}
	
	return 0;
}