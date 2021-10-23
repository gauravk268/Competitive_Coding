#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int T;
	cin >> T;
	while(T--)
	{
	    int n;
	    cin >> n;
	    int c[n];
	    for(int i=0;i<n;i++)
	    {
	        cin >> c[i];
	    }
	    
	    stack<int> s;
	    vector<int> v;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(s.size()==0)
	        v.push_back(-1);
	        else if(s.size()>0 && c[s.top()]>c[i])
	        v.push_back(s.top());
	        else
	        {
	            while(s.size()>0 && c[s.top()]<=c[i])
	            s.pop();
	            if(s.size()==0)
	            v.push_back(-1);
	            else
	            v.push_back(s.top());
	        }
	        s.push(i);
	    }
	    v[0]=1;
	    for(int i=1;i<n;i++)
	    {
	        
	        if(v[i]==-1)
	        v[i]=i+1;
	        else
	        v[i]=i-v[i];
	    }
	    for(int i=0;i<n;i++)
	    {
	        cout << v[i] << " ";
	    }
	    cout << "\n";
	}
	return 0;
}
