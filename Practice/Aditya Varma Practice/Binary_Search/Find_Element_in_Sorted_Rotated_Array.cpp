#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

bool BinarySearch(vector<int> &value,int start, int end, int number)
{
	int mid=start+((end-start)/2);
	int n;

	while(start<=end)
	{
		cout<<".";
		if(value[mid]==number)	return true;

		if(number > value[mid])		start=mid+1;
		else if(number < value[mid])	end=mid-1;

		mid=(end+start)/2;
	}

	return false;
}

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
    vector<int> value={11, 12, 15, 18, 2, 5, 6, 8};
    int n=13, index=RotationTimes(value);

    bool find;
    if(index<=0)
    {
    	find=BinarySearch(value, 0, value.size()-1, n);
    }
    else 
    {
    	int left=BinarySearch(value, 0, index, n), right=BinarySearch(value, index, value.size()-1, n);
    	find=max(left, right);
    }

    if(find==0)	cout<<"NO ";
    else	cout<<"YES ";

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