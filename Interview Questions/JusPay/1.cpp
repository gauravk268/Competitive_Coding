#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<vector<int>> g;
vector<int> vis;

void dfs(int u, vector<int> &dis, int d) {
    vis[u] = 1;
    dis[u] = d;

    for (auto v : g[u]) {
        if (!vis[v]) {
            dfs(v, dis, d + 1);
        }
    }
}

int go(vector<int> a, int b, int c) {
    int n = a.size();

    g.assign(n + 2, vector<int>());
    vector<int> dis1(n + 2, -1);
    vector<int> dis2(n + 2, -1);

    for (int i = 0; i < n; i++) {
        int v = (a[i] == -1) ? n : a[i];
        g[i].push_back(v);
    }

    vis.assign(n + 2, 0);
    dfs(b, dis1, 0);
    vis.assign(n + 2, 0);
    dfs(c, dis2, 0);

    int nmd = INT_MAX, nmc = -1;

    for (int i = 0; i < n; i++) {
        if (dis1[i] == -1 || dis2[i] == -1) {
            continue;
        }

        int cnmd = max(dis1[i], dis2[i]);
        // cout << cnmd << " ";

        if (nmd > cnmd) {
            nmd = cnmd;
            nmc = i;
        } else if (nmd == cnmd) {
            nmc = i;
        }
    }

    return nmc;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int b, c;
    cin >> b >> c;

    cout << go(a, b, c) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}