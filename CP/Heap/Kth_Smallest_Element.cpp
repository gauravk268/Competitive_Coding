#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

void kSmallestElement()
{
    vector<int> value={7, 10, 4, 3, 20, 15};
   	int k=3;
   	priority_queue<int> max_heap;

   	for(auto temp:value)
   	{
   		max_heap.push(temp);

   		if(max_heap.size()>k)
   			max_heap.pop();
   	}
   	cout<<"Result: "<<max_heap.top()<<endl;

    return;
}

int main() {
	int t=1;
	// cin>>t;

	while(t--)
	{
	    kSmallestElement();
	}
	
	return 0;
}