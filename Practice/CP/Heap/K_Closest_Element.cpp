#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

void kClosestElement()
{
    vector<int> value={5, 6, 7, 8, 9};
   	int k=3, key=7;
   	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > min_heap;

	cout<<"Result: ";
	int n=value.size();
   	for(auto temp:value)
   	{
   		int a=abs(key-temp);
   		min_heap.push(make_pair(a, temp));

   		if(min_heap.size()>n-k)
   		{
   			cout<<min_heap.top().second<<" ";
   			min_heap.pop();
   		}
   	}

    return;
}

int main() {
	int t=1;
	// cin>>t;

	while(t--)
	{
	    kClosestElement();
	    // test();
	}
	
	return 0;
}