1class Solution {
2    public void moveZeroes(int[] nums) {
3        int n = nums.length;
4        if (n == 1)
5            return;
6
7        int loc = -1;
8        for (int i = 0; i < n; i++) {
9            if (nums[i] == 0 && loc == -1) {
10                loc = i;
11            } else if (nums[i] != 0 && loc != -1) {
12                int temp = nums[i];
13                nums[i] = nums[loc];
14                nums[loc] = temp;
15                loc++;
16            }
17        }
18    }
19}