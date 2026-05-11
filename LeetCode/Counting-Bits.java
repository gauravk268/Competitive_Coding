1class Solution {
2    public int[] countBits(int n) {
3        int[] res = new int[n + 1];
4
5        if (n >= 0) {
6            res[0] = 0;
7        }
8        if (n >= 1) {
9            res[1] = 1;
10        }
11
12        int nextPow = 1, counter = 0;
13        for (int i = 2; i <= n; i++) {
14            if (--nextPow == 0) {
15                nextPow = i;
16                res[i] = 1;
17                counter = 0;
18            } else {
19                ++counter;
20                res[i] = 1 + res[counter];
21            }
22        }
23
24        return res;
25    }
26}
27