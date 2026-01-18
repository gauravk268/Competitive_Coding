1class Solution {
2    private int[][] mem;
3
4    private int helper(int[] nums, int i, int prev) {
5        if (i >= nums.length)
6            return 0;
7
8        if (mem[i][prev + 1] != -1)
9            return mem[i][prev + 1];
10
11        int res = helper(nums, i + 1, prev);
12        if (prev == -1 || nums[i] > nums[prev])
13            res = Math.max(1 + helper(nums, i + 1, i), res);
14
15        return mem[i][prev + 1] = res;
16    }
17
18    public int lengthOfLIS(int[] nums) {
19        mem = new int[nums.length][nums.length + 1];
20        for (int i = 0; i < nums.length; i++) {
21            Arrays.fill(mem[i], -1);
22        }
23        return helper(nums, 0, -1);
24    }
25}