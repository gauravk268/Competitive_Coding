1class Solution {
2    public int[] successfulPairs(int[] s, int[] p, long val) {
3        Arrays.sort(p);
4        int s_len = s.length, p_len = p.length;
5
6        int[] res = new int[s_len];
7        for (int i = 0; i < s_len; i++) {
8            int low = 0, high = p_len - 1;
9            while (low <= high) {
10                int mid = low + (high - low) / 2;
11                if ((long) s[i] * p[mid] < val) {
12                    low = mid + 1;
13                } else {
14                    high = mid - 1;
15                }
16            }
17            res[i] = p.length - high - 1;
18
19        }
20
21        return res;
22    }
23}