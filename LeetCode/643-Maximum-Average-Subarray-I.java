class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int n = nums.length;
        double res = Integer.MIN_VALUE, temp = 0;
        
        for (int i = 0; i < n; i++) {
            if (i < k) {
                temp += nums[i];
            } else {
                res = Math.max(res, temp / k);
                temp += nums[i];
                temp -= nums[i - k];
            }
        }

        res = Math.max(res, temp / k);
        return res;
    }
}