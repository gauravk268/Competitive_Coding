#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

bool BinarySearch(vector<vector<int>> &value, int key)
{
	int n=value.size()-1, m=value[0].size()-1, i=0, j=m-1;
	while(i<=n && j>=0)
	{
		if(key==value[i][j])	return true;

		if(key < value[i][j])	j--;
		else if(key > value[i][j])	i++;
	}

	return false;
}

void solve()
{
    vector<vector<int>> value={
    	{10, 20, 30, 40},
    	{15, 25, 35, 45},
    	{27, 29, 37, 48},
    	{32, 33, 39, 50}
    };
    int key=23;
    
    if(BinarySearch(value, key))	cout<<"Yes"<<endl;
    else 	cout<<"No"<<endl;

    return;
}

int main() {
	int t=1;
	// cin>>t;

	while(t--)
	{
	    solve();
	}
	
	return 0;
}