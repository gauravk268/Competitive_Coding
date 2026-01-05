1class Solution {
2    public int pivotIndex(int[] nums) {
3        int n = nums.length, sum = 0;
4        int[] left = new int[n], right = new int[n];
5
6        left[0] = 0;
7        right[n - 1] = 0;
8        for (int i = 1; i < n; i++) {
9            left[i] = nums[i - 1] + left[i - 1];
10            right[n - i - 1] = nums[n - i] + right[n - i];
11        }
12
13        for (int i = 0; i < n; i++) {
14            if (left[i] == right[i])
15                return i;
16        }
17
18        return -1;
19    }
20}