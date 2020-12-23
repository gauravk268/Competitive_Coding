#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

bool BinarySearch(vector<int> &value, int number)
{
	int start=0, end=value.size()-1, mid;
	int n;

	while(start<=end)
	{
		cout<<".";
		mid=start+((end-start)/2);
		
		if(value[mid]==number)	return true;

		if(number > value[mid])		start=mid+1;
		else if(number < value[mid])	end=mid-1;
	}

	return false;
}

void solve()
{
    vector<int> value={2, 4, 6, 7, 8, 10};
    int n=6;
    if(BinarySearch(value, n))	cout<<"YES"<<endl;
    else 	cout<<"NO"<<endl;

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