#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

int BinarySearch(vector<int> &value, int number)
{
	int mid, n=value.size(), start=0, end=n-1, result;

	if(number<value[0])
		return -1;
	else while(start<=end)
	{
		cout<<".";
		mid=start+((end-start)/2);

		if(value[mid]==number)	return value[mid];

		if(number > value[mid]){	
			result=mid;
			start=mid+1;
		}
		else if(number < value[mid])	end=mid-1;
	}

	return value[result];
}

void solve()
{
    vector<int> value={1, 2, 3, 4, 8, 10, 10, 12, 19};

    for(int i=0; i<25; i++)
    {
    	cout<<i<<" "<<BinarySearch(value, i)<<"\n";
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