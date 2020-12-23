#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

bool BinarySearch(vector<int> &value, int number)
{
	int mid, n=value.size(), start=0, end=n-1;

	while(start<=end)
	{
		cout<<".";
		mid=start+((end-start)/2);

		if(value[mid]==number || value[(mid+n-1)%n]==number || value[(mid+1)%n]==number)	return true;

		if(number > value[mid])		start=mid+1;
		else if(number < value[mid])	end=mid-1;
	}

	return false;
}

void solve()
{
    vector<int> value={5, 10, 30, 20, 40};
    int n=5;

    for(int i=5; i<50; i+=5)
    {
    	cout<<i<<" ";
    	if(BinarySearch(value, i)==0)	cout<<"NO\n";
    	else	cout<<"YES\n";
    }

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