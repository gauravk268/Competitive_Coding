#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

char FindNextElement(vector<char> &value, char element)
{
	int mid, n=value.size(), start=0, end=n-1, result;

	if(element>value[n-1])
		return '0';
	else while(start<=end)
	{
		cout<<".";
		mid=start+((end-start)/2);

		if(value[mid]==element)	return value[mid];

		if(element > value[mid]){
			start=mid+1;
		}
		else if(element < value[mid])
		{
			result=mid;
			end=mid-1;
		}
	}

	return value[result];
}

void solve()
{
    vector<char> value={'a', 'c', 'f', 'h'};

    for(char i='a'; i<='z'; i++)
    {
    	cout<<i<<" "<<FindNextElement(value, i)<<"\n";
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