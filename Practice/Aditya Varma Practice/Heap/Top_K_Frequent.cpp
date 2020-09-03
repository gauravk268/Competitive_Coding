#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

void TopKFrequent()
{
    vector<int> value={1, 2, 3, 3, 2, 3, 4};
   	int k=2;
   	priority_queue< pair<int, int> > max_heap;
    unordered_map<int, int> frequencyCount;

  	cout<<"Result: ";
    for(auto temp:value)
      frequencyCount[temp]++;

    for(auto temp:frequencyCount)
      max_heap.push(make_pair(temp.second, temp.first));

    for(int i=0; i<k; i++)
    {
      cout<<max_heap.top().second<<" ";
      max_heap.pop();
    }
  	

    return;
}

int main() {
	int t=1;
	// cin>>t;

	while(t--)
	{
	    TopKFrequent();
	}
	
	return 0;
}