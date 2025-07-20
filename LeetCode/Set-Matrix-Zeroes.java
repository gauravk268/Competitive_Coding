class Solution {
    public void setZeroes(int[][] mat) {
        int m=mat.length, n=mat[0].length;
    
        boolean[] row = new boolean[200];
        boolean[] col = new boolean[200];


        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(row[i] == true || col[j] == true){
                    mat[i][j] = 0;
                }
            }
        }
    }
}