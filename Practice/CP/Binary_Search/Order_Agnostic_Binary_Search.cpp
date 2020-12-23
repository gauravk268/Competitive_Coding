#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

bool reverseBinarySearch(vector<int> &value, int number)
{
	int start=0, end=value.size()-1, mid=start+((end-start)/2);
	int n;

	while(start<=end)
	{
		cout<<".";
		if(value[mid]==number)	return true;

		if(number > value[mid])		end=mid-1;
		else if(number < value[mid])	start=mid+1;

		mid=(end+start)/2;
	}

	return false;
}

bool BinarySearch(vector<int> &value, int number)
{
	int start=0, end=value.size()-1, mid=start+((end-start)/2);
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

void solve()
{
    vector<int> value={20, 17, 15, 14, 13, 12, 10, 9, 8, 4};
    int n=4;
    
    if(value.size()==1)
    {
        if(value[0]==n) cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;
    }
    else
    {
        if(value[0]>value[1])
        {
            if(reverseBinarySearch(value, n)) cout<<"YES"<<endl;
            else    cout<<"NO"<<endl;
        }
        else if(value[1]>value[0])
        {
            if(BinarySearch(value, n)) cout<<"YES"<<endl;
            else    cout<<"NO"<<endl;
        }
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