1class Solution {
2    public int rob(int[] nums) {
3        int n = nums.length;
4        if (n == 0)
5            return 0;
6        if (n == 1) {
7            return nums[0];
8        }
9
10        int[] mem = new int[n + 1];
11
12        mem[0] = 0;
13        mem[1] = nums[0];
14
15        for (int i = 2; i <= n; i++) {
16            mem[i] = Math.max(nums[i - 1] + mem[i - 2], mem[i - 1]);
17        }
18
19        return mem[n];
20    }
21}