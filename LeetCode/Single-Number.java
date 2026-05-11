1class Solution {
2    public int singleNumber(int[] nums) {
3        int n = nums.length;
4        int res = 0;
5        for (int i = 0; i < n; i++) {
6            res = res ^ nums[i];
7        }
8        return res;
9    }
10}