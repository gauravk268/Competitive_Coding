class Solution
{
public:
    void dfs(vector<vector<int>> &adj, vector<vector<int>> &nadj, vector<set<int>> &values, int k)
    {
        values[k].insert(k);
        for (auto x : adj[k])
        {
            values[k].insert(x);
            for (auto y : values[x])
                values[k].insert(y);
        }

        for (auto child : nadj[k])
        {
            dfs(adj, nadj, values, child);
        }
    }

    vector<int> maxGeneticDifference(vector<int> &p, vector<vector<int>> &q)
    {
        int n = p.size();
        vector<vector<int>> adj(n), nadj(n);
        vector<set<int>> values(n);

        int root;
        for (int i = 0; i < n; i++)
        {
            if (p[i] == -1)
                root = i;
            else
            {
                adj[i].push_back(p[i]);
                nadj[p[i]].push_back(i);
            }
        }

        dfs(adj, nadj, values, root);

        vector<int> result;
        for (auto &x : q)
        {
            int node = x[0];
            int value = x[1];
            int res = 0;

            // cout << x[0] << ": ";
            for (auto y : values[x[0]])
            {
                // cout << y << " ";
                res = max(res, value ^ y);
            }
            // cout << endl;

            result.push_back(res);
        }

        return result;
    }
};