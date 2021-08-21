#include<bits/stdc++.h>
using namespace std;

#define endl 	"\n"
#define N  		8

// #define ENABLE_DEBUG

// int dx[8] = {2,  2, 1,  1, -1, -1, -2, -2};
// int dy[8] = {1, -1, 2, -2,  2, -2,  1, -1};

int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool isValid(int x, int y, int chess[N][N])
{
	return (x >= 0 && y >= 0 && x < N && y < N && chess[x][y] == -1);
}

void printChess(int chess[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << " " << setw(2) << chess[i][j] << " ";
		cout << endl;
	}
}

int solveKT(int x, int y, int countMove, int chess[N][N])
{
	if (countMove == N * N )
		return 1;

	for (int i = 0; i < N; i++)
	{
		int newX = x + dx[i];
		int newY = y + dy[i];

		if (isValid(newX, newY, chess))
		{
			chess[newX][newY] = countMove;
			if (solveKT(newX, newY, 1 + countMove, chess))
			{
				return 1;
			}
			else
				chess[newX][newY] = -1;
		}
	}

	return 0;
}


void solution()
{
	int chess[N][N];
	memset(chess, -1, sizeof(chess));
	chess[0][0] = 0;

	if (solveKT(0, 0, 1, chess) == 0)
	{
		cout << "NO SOLUTION\n";
		return;
	}
	else
		printChess(chess);

	return;
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

/*
Input

Output
*/