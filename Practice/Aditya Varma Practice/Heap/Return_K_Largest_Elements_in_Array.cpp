#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

void kLargestElements()
{
    vector<int> value={7, 10, 4, 3, 20, 15};
   	int k=3;
   	priority_queue<int, vector<int>, greater<int>> min_heap;

   	for(auto temp:value)
   	{
   		min_heap.push(temp);

   		if(min_heap.size()>k)
   			min_heap.pop();
   	}
   	cout<<"Result: ";

   	while(!min_heap.empty())
   	{
   		cout<<min_heap.top()<<" ";
   		min_heap.pop();
   	}

    return;
}

int main() {
	int t=1;
	// cin>>t;

	while(t--)
	{
	    kLargestElements();
	}
	
	return 0;
}