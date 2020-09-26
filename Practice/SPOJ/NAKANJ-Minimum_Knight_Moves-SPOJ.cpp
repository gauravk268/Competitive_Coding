#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define endl     "\n"
#define MOD      1000000007
#define deb(x) 	 cout<<#x<<"="<<x<<endl

#define f  first
#define s  second
#define pb push_back
#define mp make_pair

// #define ENABLE_DEBUG


pair<int, int> stringToInt(string v)
{
	return {v[0] - 'a', v[1] - '0' - 1};
}

int dx[8] = {1, 2,  2,  1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2,  2,  1, -1, -2};
int dist[8][8];

bool isValid(int x, int y)
{
	return (x >= 0 && x < 8 && y >= 0 && y < 8 && dist[x][y] == -1);
}

void solveKT(pair<int, int> start, pair<int, int> end)
{
	int newX, newY;
	queue<pair<int, int> > q;
	q.push(start);
	dist[start.f][start.s] = 0;

	while (!q.empty())
	{
		pair<int, int> p;
		p = q.front();	q.pop();
		int x = p.f, y = p.s;

		for (int i = 0; i < 8; i++)
		{
			newX = x + dx[i];
			newY = y + dy[i];

			if (isValid(newX, newY))
			{
				dist[newX][newY] = 1 + dist[x][y];
				q.push({newX, newY});
			}
		}
	}
}

void solution()
{
	string start, end;
	cin >> start >> end;

	pair<int, int> a, b;
	a = stringToInt(start);
	b = stringToInt(end);

	solveKT(a, b);
	cout << dist[b.f][b.s] << endl;
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
	cin >> t;

	while (t--)
	{
		memset(dist, -1, sizeof(dist));
		solution();
	}

	return 0;
}

/*
Input:
3
a1 h8
a1 c2
h8 c3

Output:
6
1
4
*/