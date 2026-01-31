1class Solution {
2    private int helper(int[] p, long k) {
3        int res = 0;
4        for (int i : p) {
5            res += (i % k == 0) ? i / k : (i / k) + 1;
6        }
7        return res;
8    }
9
10    public int minEatingSpeed(int[] piles, int h) {
11        long low = 1, high = 0;
12
13        for (int i : piles) {
14            high += i;
15        }
16
17        while (low <= high) {
18            long mid = low + (high - low) / 2;
19            int res = helper(piles, mid);
20
21            if (res > h)
22                low = mid + 1;
23            else
24                high = mid - 1;
25        }
26
27        return (int)low;
28    }
29}