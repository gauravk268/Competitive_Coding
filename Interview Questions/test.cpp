#include <bits/stdc++.h>
using namespace std;
class cmp
{
public:
    bool operator()(std::vector<int> &a, std::vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
};

bool check(std::vector<std::vector<int>> &s, double x)
{
    double y;
    for (int i = 0; i < s.size(); i++)
    {
        if (i == 0)
        {
            if (s[i][0] + x <= s[i][1])
                y = s[i][0] + x;

            else
                return false;
        }
        else
        {
            if (y < s[i][0])
                y = s[i][0];
            if (y + x <= s[i][1])
                y = y + x;
            else
                return false;
        }
    }
    return true;
}

double equalDisconnectedSegments(std::vector<std::vector<int>> segments)
{
    sort(segments.begin(), segments.end(), cmp());
    double r = INT_MAX;
    for (int i = 0; i < segments.size(); i++)
    {
        r = std::min(r, double(segments[i][1] - segments[i][0]));
    }
    double l = 0;
    double mid = 0;
    double ans = r;
    while (r - l > (0.0000001))
    {
        mid = l + (r - l) / 2;
        if (check(segments, mid))
        {
            ans = mid;
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return ans;
}
// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(2, 0));
        for (int i = 0; i < n; i++)
        {
            cin >> v[i][0] >> v[i][1];
        }
        cout << equalDisconnectedSegments(v) << endl;
    }
    return 0;
}
// } Driver Code Ends