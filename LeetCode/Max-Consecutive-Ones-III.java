1class Solution {
2    public int longestOnes(int[] nums, int k) {
3        int n = nums.length, len = 0, j = 0;
4
5        for (int i = 0; i < n; i++) {
6            if (nums[i] == 0) {
7                if (k != 0) {
8                    k--;
9                } else {
10                    while (nums[j] != 0) {
11                        j++;
12                    }
13                    j++;
14                }
15            }
16
17            len = Math.max(len, i - j + 1);
18        }
19
20        return len;
21    }
22}