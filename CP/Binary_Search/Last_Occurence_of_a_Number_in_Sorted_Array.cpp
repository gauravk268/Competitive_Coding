#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

int LastOccur(vector<int> &value, int number)
{
	int start=0, end=value.size()-1, mid=start+((end-start)/2);
	int n, result;

	while(start!=end)
	{
		cout<<".";
		if(value[mid]==number)
		{
			if(mid==value.size()-1 || value[mid+1]!=value[mid])
				return mid;

			result=mid;
			mid++;
			continue;
		}

		if(number > value[mid])		start=mid+1;
		else if(number < value[mid])	end=mid-1;

		mid=(end+start)/2;
	}

	return -1;
}

void solve()
{
    vector<int> value={2, 4, 10, 10, 10, 18, 20};
    int n=10;
    cout<<LastOccur(value, n);

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