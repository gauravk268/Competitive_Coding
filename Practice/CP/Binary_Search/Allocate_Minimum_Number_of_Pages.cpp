#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

bool isValid(vector<int> &value, int maxStudents, int maxPages)
{
	int n=value.size(), sum=0, student=1;
	for(int i=0; i<n; i++)
	{
		sum+=value[i];
		if(sum>maxPages)
		{
			student++;
			sum=value[i];
		}
	}

	if(student>maxStudents)	return false;
	return true;
}

void solve()
{
    vector<int> books={10, 20, 30, 40, 50};
    int maxStudents=2, maxPages, mid, result;
    int start=*max_element(books.begin(), books.end());
    int end=accumulate(books.begin(), books.end(), 0);

    while(start<=end)
    {
    	mid=start+((end-start)/2);

    	if(isValid(books, maxStudents, mid))
    	{
    		result=mid;
    		end=mid-1;
    	}
    	else
    	{
    		start=mid+1;
    	}
    }

    cout<<result;
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