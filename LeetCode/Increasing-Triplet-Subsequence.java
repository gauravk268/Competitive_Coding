1class Solution {
2    public boolean increasingTriplet(int[] nums) {
3        int n = nums.length;
4        int[] pre = new int[n], post = new int[n];
5
6        pre[0] = nums[0];
7        for (int i = 1; i < n; i++) {
8            pre[i] = (pre[i - 1] < nums[i]) ? pre[i - 1] : nums[i];
9        }
10
11        post[n - 1] = nums[n - 1];
12        for (int i = n - 2; i >= 0; i--) {
13            post[i] = (post[i + 1] > nums[i]) ? post[i + 1] : nums[i];
14        }
15
16        for(int i=1; i<n-1; i++){
17            if(pre[i] < nums[i] && post[i] > nums[i])
18                return true;
19        }
20
21        return false;
22    }
23}