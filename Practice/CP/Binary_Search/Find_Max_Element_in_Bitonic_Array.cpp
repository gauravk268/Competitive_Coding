#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

int PeakElement(vector<int> &value)
{
	int n=value.size(), start=0, end=n-1, mid;

	while(start<=end)
	{
		mid=start+((end-start)/2);

		if(n==1 || value[0]>value[1])
			return 0;
		else if(value[n-1]>value[n-2])
			return n-1;
		
		if(value[mid]>value[mid-1] && value[mid]>value[mid+1])
				return mid;
		if(value[mid]<value[mid-1])	end=mid-1;
		else if(value[mid]<value[mid+1])	start=mid+1;
	}

	return -1;
}

void solve()
{
    vector<int> value={1, 3, 8, 12, 4, 2};
    
    cout<<PeakElement(value)<<endl;

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