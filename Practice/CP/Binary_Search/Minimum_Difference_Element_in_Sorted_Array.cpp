#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

int BinarySearch(vector<int> &value, int element)
{
	int start=0, end=value.size()-1, mid, n=value.size();

	while(start<=end)
	{
		mid=start+((end-start)/2);

		if(value[mid]==element)	return element;

		if(element>value[mid])	start=mid+1;
		else if(element<value[mid])		end=mid-1;
	}

	int diffStart=abs(value[start]-element), diffEnd=abs(value[end]-element);
	
	if(diffStart < diffEnd)		return value[start];
	else 	return value[end];
}

void solve()
{
    vector<int> value={1 ,3 ,8, 10, 12, 15};
    int n=5;

    for(int i=0; i<20; i++)
    {
    	cout<<i<<" "<<BinarySearch(value, i)<<endl;
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