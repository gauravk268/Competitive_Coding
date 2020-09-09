#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

void solution()
{
    vector<int> value={1, 2, 3, 4, 5};
   	int k=3;
   	priority_queue<int, vector<int>, greater<int>> min_heap;

   	for(auto temp:value)
   		min_heap.push(temp);

    int cost=0;
    while(min_heap.size()!=1)
    {
      int a=min_heap.top();   min_heap.pop();
      int b=min_heap.top();   min_heap.pop();

      cost+=a+b;
      min_heap.push(a+b);
    }
   	cout<<"Result: "<<cost<<endl;

    return;
}

int main() {
	int t=1;
	// cin>>t;

	while(t--)
	{
	    solution();
	}
	
	return 0;
}