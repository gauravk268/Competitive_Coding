#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

void sortKSortedArray()
{
    vector<int> value={6, 5, 3, 2, 8, 10, 9};
   	int k=3;
   	priority_queue<int, vector<int>, greater<int>> min_heap;

    cout<<"Result: ";
   	for(auto temp:value)
   	{
   		min_heap.push(temp);

   		if(min_heap.size()>k)
      {
        cout<<min_heap.top()<<"-> ";
        min_heap.pop();
      }
   	}

    while(!min_heap.empty())
    {
        cout<<min_heap.top()<<"-> ";
        min_heap.pop();
    }
   	
    return;
}

int main() {
	int t=1;
	// cin>>t;

	while(t--)
	{
	    sortKSortedArray();
	}
	
	return 0;
}