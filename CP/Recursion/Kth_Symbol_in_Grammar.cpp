#include<bits/stdc++.h>
using namespace std;

#define ll     long long
#define endl   "\n"
#define MOD    1e9+7
#define deb(x) cout<<#x<<"="<<x<<endl

#define f  first
#define s  second
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef deque<int>  di;
typedef stack<int>  si;
typedef priority_queue<int> max_heap;
typedef priority_queue<int, vector<int>, greater<int>> min_heap;
typedef pair<int, int> 		 pi;
typedef tuple<int, int, int> ti;

void printVector(vector<int> &value){ for(auto temp:value){ cout<<temp<<" "; } cout<<"\n";}

// #define ENABLE_DEBUG


class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N==1 && K==1)
            return 0;
        
        int mid = pow(2, N-1)/2;
        
        if(K<=mid)  return kthGrammar(N-1, K);
        else    return !kthGrammar(N-1, K-mid);
    }
};

void solve()
{	
	int N=1, K=1;	//0
	// int N=2, K=1;	//0
	// int N=2, K=2;	//1
	// int N=4, K=5;	//1

	Solution result;
	cout<<result.kthGrammar(N, K)<<endl;
	
    return;
}

int main() 
{
	#ifdef ENABLE_DEBUG
		freopen("input.txt" , "r", stdin );
		freopen("output.txt", "w", stdout);
	#endif

	int t=1;
	// cin>>t;

	while(t--)
	{
		cout<<"Result: \n";
	    solve();
	}
	
	return 0;
}