1class Solution {
2    public boolean canPlaceFlowers(int[] fb, int k) {
3        int res=0, n=fb.length;
4
5        for(int i=0; i<n; i++){
6            if(fb[i] == 1){
7                i++;
8            }else{
9                if(i<n-1 && fb[i+1] == 0 || i==n-1){
10                    res++;
11                    i++;
12                }
13            }
14        }
15
16        return res >= k;
17    }
18}