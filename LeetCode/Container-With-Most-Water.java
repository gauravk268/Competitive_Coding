1class Solution {
2    public int maxArea(int[] h) {
3        int n=h.length;
4
5        int i=0, j=n-1, res=0;
6        while(i<j){
7            res = Math.max(res, Math.min(h[i], h[j])*(j-i));
8
9            if(h[i] < h[j]) i++;
10            else j--;
11        }
12
13        return res;
14    }
15}