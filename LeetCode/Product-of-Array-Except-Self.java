1class Solution {
2    public int[] productExceptSelf(int[] nums) {
3        int n = nums.length, numZero = 0;
4        int prod = 1;
5
6        for (int i = 0; i < n; i++) {
7            if (nums[i] == 0) {
8                numZero++;
9            } else {
10                prod = prod * nums[i];
11            }
12        }
13
14        if (numZero > 1) {
15            for (int i = 0; i < n; i++) {
16                nums[i] = 0;
17            }
18        } else if (numZero == 1) {
19            for (int i = 0; i < n; i++) {
20                nums[i] = (nums[i] == 0) ? prod : 0;
21            }
22        } else{
23            for (int i = 0; i < n; i++) {
24                nums[i] = prod / nums[i];
25            }
26        }
27
28        return nums;
29    }
30}