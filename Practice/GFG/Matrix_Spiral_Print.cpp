#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;

#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define bk back()
#define pb push_back
#define endl "\n"
#define dotl " "

#define fr1(i, a, b) for (int i = (a); i <= (b); ++i)
#define fr(i, a) fr1(i, 0, a)
#define rf1(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define rf(i, a) rf1(i, 0, a)
#define trav(x, a) for (auto &x : a)

#define deb(x) cout << #x << "=" << x << endl
#define showRunTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define ONLINE_JUDGE freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

const int MX = 2e5 + 5;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7; // used in most problems
const ld PI = acos(-1);	 // inverse cos of -1

void solution()
{
	int row, col;
	cin >> row >> col;
	int mat[row][col];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> mat[i][j];
		}
	}

	int i, k = 0, l = 0;
	while (k < row && k < col)
	{
		for (i = l; i < col; i++)
		{
			cout << mat[k][i] << " ";
		}
		k++;

		for (i = k; i < row; i++)
		{
			cout << mat[i][col - 1] << " ";
		}
		col--;

		if (k < row)
		{
			for (i = col-1; i >= l; i--)
			{
				cout << mat[row - 1][i] << " ";
			}
			row--;
		}

		if (l < col)
		{
			for (i = row-1; i >= k; i--){
				cout << mat[i][l] << " ";
			}
			l++;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	ONLINE_JUDGE;
	cin >> t;

	while (t--)
	{
		cerr << " end " << endl;
		solution();
	}

	showRunTime;
	return 0;
}

/*
2
4 4s
1 2 3 4 
5 6 7 8 
9 10 11 12 
13 14 15 16
3 6
1 2 3 4 5 6 
7 8 9 10 11 12 
13 14 15 16 17 18

*/