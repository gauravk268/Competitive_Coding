class Solution{   
public:
    int median(vector<vector<int>> &mat, int r, int c){
        int minV=INT_MAX, maxV=INT_MIN;
        
        for(int i=0; i<r; i++){
            minV = min(minV, mat[i][0]);
            maxV = max(maxV, mat[i][c-1]);
        }
        
        int desired=((r*c)+1)/2;
        while(minV < maxV){
            int mid = minV + (maxV - minV)/2;
            int place=0;
            
            for(int i=0; i<r; i++)  
                place += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();

            if(place < desired)     minV=mid+1;
            else    maxV=mid;
        }
        
        return minV;
    }
};