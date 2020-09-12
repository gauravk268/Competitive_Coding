#include<bits/stdc++.h>
using namespace std;

#define ll     long long
#define endl   "\n"
#define MOD    1000000007
#define deb(x) cout<<#x<<"="<<x<<endl
#define fLoop(n)	for(int i=1; i<=n; i++)

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


//To print binary equivalent of a binary number
void printBinary(unsigned n)
{
    unsigned i;
    for (i = 1 << 15; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
    cout << "\n";
}


// Fast way to calculate power of a large number
ll powerFast(ll a, ll b)
{
    // 3^10 == (3*3)^(10/2)
    // keep on repeating until the power cannot be divided

    a%=MOD;
    ll result =1;
    while(b>0){
        if(b%2 == 1){
            result *= a;
            result %= MOD;
        }

        a*=a;   a%=MOD;
        b/=2;
    }
    
    return result;
}


void solution()
{

}

int main()
{
	#ifdef ENABLE_DEBUG
		freopen("input.txt" , "r", stdin );
		freopen("output.txt", "w", stdout);
	#endif

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin>>t;

	while (t--)
	{
		solution();
	}

	return 0;
}