#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl "\n"
#define dotl " "
#define MOD 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#define f first
#define s second
#define pb push_back
#define pii pair<int, int>
#define mp make_pair

// void solution()
// {
//   string bin;   cin>>bin;
//   stack<char> s;
//   ll n=bin.length();

//   if(n%2){
//     cout<<-1<<endl;
//     return;
//   }
    
//   for(ll i=0; i<n; i++)
//   {
//     if(s.empty()){
//       s.push(bin[i]);
//     }
//     else{
//       if(!s.empty() && s.top() == bin[i]){
//         s.push(bin[i]);
//       }
//       else if(!s.empty() && s.top()!=bin[i]){
//         s.pop();
//       }
//     }
//   }

//   ll rem = s.size();

//   // int nRem=0;
//   // if(!s.empty()){
//   //   char m = s.top();
//   //   while(!s.empty()){
//   //     if(s.top()==m)
//   //       nRem++;
//   //     s.pop();
//   //   }
//   // }
  
//   cout<<(rem/2)<<endl;
// }

void solution(){
  string bin;   cin>>bin;
  ll n=bin.length();

  if(n%2)
    cout<<-1<<endl;
  else{
    int c0=0, c1=0;

    for(int i=0; i<n; i++){
      if(bin[i]=='1') c1++;
      else  c0++;
    }

    if(c0==0 || c0==n || c1==0 || c1==n){
      cout<<-1<<endl;
      return;
    }

    if(c1==c0)  cout<<0<<endl;
    else{
      cout<<abs(n/2 - min(c0, c1))<<endl;
    }
  }
}

int main(){
	// ONLINE_JUDGE;

	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;

	while (t--)
	{
		solution();
	}

	showRunTime;
	return 0;
}

/*

Example Input
3
001101
1101
110
Example Output
0
1
-1

*/