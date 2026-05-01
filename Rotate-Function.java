1class Solution {
2    public int maxRotateFunction(int[] nums) {
3        int n = nums.length;
4
5        long res = 0, sum = 0;
6        for (int i = 0; i < n; i++) {
7            res += i * nums[i];
8            sum += nums[i];
9        }
10
11        long prev = res;
12        for (int i = 1; i < n; i++) {
13            long curr = prev + sum - (long) n * nums[n - i];
14            res = Math.max(res, curr);
15            prev = curr;
16        }
17
18        return (int) res;
19    }
20}