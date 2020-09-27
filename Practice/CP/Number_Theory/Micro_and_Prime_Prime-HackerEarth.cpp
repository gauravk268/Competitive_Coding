
#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define endl     "\n"
#define MOD      1000000007
#define deb(x) 	 cout<<#x<<"="<<x<<endl
#define range 	 1000001

// #define ENABLE_DEBUG

int ar[range], value[range];

bool isPrime(int n)
{
	if (n == 1 || n == 0)	return false;

	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)		return false;

	return true;
}

void countPrime()
{
	int count=0, temp=0;
	ar[0]=ar[1]=0;

	for(int i=1; i<=range; i++)
	{
		if(isPrime(i))	count++;
		ar[i]=count;

		if(isPrime(ar[i]))	temp++;
		value[i]=temp;	
	}
}

void solution()
{
	int a, b;
	cin >> a >> b;

	cout<<value[b]-value[a-1]<<endl;
}


int main()
{
#ifdef ENABLE_DEBUG
	freopen("input.txt" , "r", stdin );
	freopen("output.txt", "w", stdout);
#endif

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	countPrime();

	int t = 1;
	cin >> t;

	while (t--)
	{
		solution();
	}

	return 0;
}

/*
SAMPLE INPUT 
2
3 10
4 12

SAMPLE OUTPUT 
4
5
*/