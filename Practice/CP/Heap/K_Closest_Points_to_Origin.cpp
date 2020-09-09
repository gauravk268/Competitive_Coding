#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

void kClosestPointToOrigin()
{
    vector<vector<int>> value={{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
   	int k=2;
   	priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > min_heap;

    cout<<"Result: ";
    int n=value.size();
  	for(auto temp:value)
  	{
  		int dist=pow(pow(temp[0], 2)+pow(temp[1], 2), 0.5);
  		min_heap.push(make_pair(dist, make_pair(temp[0], temp[1])));

  		if(min_heap.size()>k)
  		{
  			cout<<min_heap.top().second.first<<" "<<min_heap.top().second.second<<endl;
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
	    kClosestPointToOrigin();
	    // test();
	}
	
	return 0;
}