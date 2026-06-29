1class Solution {
2    public int minCostClimbingStairs(int[] cost) {
3        int n = cost.length;
4        int[] mem = new int[n+1];
5
6        mem[n]=0;
7        mem[n-1]=cost[n-1];
8
9        for(int i=n-2; i>=0; i--){
10            mem[i] = cost[i] + Math.min(mem[i+1], mem[i+2]);
11        }
12
13        return Math.min(mem[0], mem[1]);
14    }
15}