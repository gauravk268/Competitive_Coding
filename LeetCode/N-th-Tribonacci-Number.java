1class Solution {
2    int[] mem = new int[38];
3
4    public int tribonacci(int n) {
5        mem[0] = 0;
6        mem[1] = 1;
7        mem[2] = 1;
8
9        for (int i = 3; i <= n; i++) {
10            mem[i] = mem[i - 3] + mem[i - 2] + mem[i - 1];
11        }
12
13        return mem[n];
14    }
15}