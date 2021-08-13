class Solution {
public:
    int time(int x1, int y1, int x2, int y2)
    {
        return max(abs(x1-x2), abs(y1-y2));
    }
    
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {
        int n=points.size();
        int result=0;
        for(int i=1; i<n; i++)
        {
            result += time(points[i][0], points[i][1], points[i-1][0], points[i-1][1]);
        }
        
        return result;
    }
};