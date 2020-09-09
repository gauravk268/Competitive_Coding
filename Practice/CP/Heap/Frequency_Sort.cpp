#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

void frequencySort()
{
    vector<int> value={4, 2, 3, 3, 2, 3, 1};
   	int k=2;
   	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > min_heap;
    unordered_map<int, int> frequencyCount;

  	cout<<"Result: ";
    for(auto temp:value)
      frequencyCount[temp]++;

    for(auto temp:frequencyCount)
      min_heap.push(make_pair(temp.second, temp.first));

    while(min_heap.size()>0)
    {
      cout<<min_heap.top().second<<" ";
      min_heap.pop();
    }
  	
    return;
}

int main() {
	int t=1;
	// cin>>t;

	while(t--)
	{
	    frequencySort();
	}
	
	return 0;
}