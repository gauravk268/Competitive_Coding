1class Solution {
2    public double findMaxAverage(int[] nums, int k) {
3        int n = nums.length, sum = Integer.MIN_VALUE, tempSum = 0;
4        int i = 0, j = 0;
5
6        while (i < n) {
7            if (i < k) {
8                tempSum += nums[i];
9            } else {
10                tempSum += nums[i];
11                tempSum -= nums[j];
12                j++;
13            }
14            
15            i++;
16            if (i >= k) {
17                sum = Math.max(sum, tempSum);
18            }
19        }
20
21        return (double) sum / k;
22    }
23}