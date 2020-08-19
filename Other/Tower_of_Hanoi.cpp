#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl


#define ENABLE_DEBUG


void Toi(int start, int destination, int helper, int value)
{
    if(value==1)
    {
        cout<<"Move disk "<<value<<" from "<<start<<" to "<<destination<<"\n";
        return;
    }
    
    Toi(start, helper, destination, value-1);
    cout<<"Move disk "<<value<<" from "<<start<<" to "<<destination<<"\n";
    Toi(helper, destination, start, value-1);
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t=1;
// 	cin>>t;

	while(t--)
	{
	   Toi(1, 3, 2, 3);
	}
	
	return 0;
}