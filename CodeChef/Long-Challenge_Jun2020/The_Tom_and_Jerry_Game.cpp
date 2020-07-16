#include <bits/stdc++.h>
using namespace std;

#define fo(i, a) for (int i = 0; i < a; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define MEM(a, b, n) memset(a, b, sizeof(a[0]) * n)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define gc getchar_unlocked
#define ll long long
#define endl "\n"

typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

const int MOD = 1e9 + 7;
const int SIZE_INT = 16;

void solve()
{
    ll tom, result;
    cin >> tom;

    if (tom % 2 == 1)
    {
        result = tom / 2;
    }
    else
    {
        ll temp = tom, count = 0;
        while (temp % 2 == 0)
        {
            temp /= 2;
            count++;
        }

        result = temp / 2;
    }

    cout << result << endl;
}

int main()
{
    //a line to speed-up
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int testCases = 1;
    cin >> testCases; //remove it if only 1 testcase
    while (testCases--)
    {
        solve();
    }

    return 0;
}