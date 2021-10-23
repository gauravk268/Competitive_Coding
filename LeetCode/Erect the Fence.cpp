class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<vector<int>> ans;
        sort(points.begin(), points.end(), mycompare);
        
        for (int i = 0; i < n; ++i) {
            while (ans.size() > 1 && orientation(ans[ans.size()-2], ans.back(), points[i]) < 0) 
                ans.pop_back();
            ans.push_back(points[i]);
        }
        
        if (ans.size() == n) return ans;
        
        for (int i = n-2; i >= 0; --i) {
            while (ans.size() > 1 && orientation(ans[ans.size()-2], ans.back(), points[i]) < 0) 
                ans.pop_back();
            ans.push_back(points[i]);
        }
        ans.pop_back();
        return ans;
    }
    static bool mycompare(vector<int>& a, vector<int>& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    }
    int orientation(vector<int>& a, vector<int>& b, vector<int>& c) {
        return (b[0] - a[0])*(c[1] - b[1]) - (b[1] - a[1])*(c[0] - b[0]);
    }
};
