class Solution {
    public void rotate(int[][] m) {
        int n=m.length;
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                int k = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = k;
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n/2; j++){
                int k = m[i][j];
                m[i][j] = m[i][n-j-1];
                m[i][n-j-1] = k;
            }
        }
    }
}