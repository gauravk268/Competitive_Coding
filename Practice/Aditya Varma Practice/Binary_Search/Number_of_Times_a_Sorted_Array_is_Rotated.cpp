#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

int RotationTimes(vector<int> &value)
{
	int start=0, end=value.size()-1, n=value.size(), mid;

	if(value[0]<value[n-1])
		return 0;
	else while(start<=end)
	{
		cout<<".";
		mid=start+((end-start)/2);

		if(value[mid]<=value[(mid+1)%n] && value[mid]<=value[(mid+n-1)%n])
		{
			return mid;
		}

		if(value[start]<=value[mid])	start=mid;
		else if(value[mid]<=value[end])	end=mid;
	}

	return -1;
}

void solve()
{
    vector<int> value={11, 13, 15, 18, 2, 5, 6, 8};

    cout<<RotationTimes(value)<<endl;

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