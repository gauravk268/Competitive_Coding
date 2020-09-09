#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl

int kSmallestElement(vector<int> &value, int k)
{
    priority_queue<int> max_heap;

   	for(auto temp:value)
   	{
   		max_heap.push(temp);

   		if(max_heap.size()>k)
   			max_heap.pop();
   	}
   	return max_heap.top();
}

int main() {
	int t=1;
	// cin>>t;

	while(t--)
	{
      vector<int> value={1, 3, 12, 5, 15, 11};
      int k1=3, k2=6;
      int first=kSmallestElement(value, k1);
      int second=kSmallestElement(value, k2);

      cout<<"Result: ";
      for(int i=0; i<value.size(); i++)
      {
        if(value[i]<second && value[i]>first)
          cout<<value[i]<<" ";
      }
	}
	
	return 0;
}