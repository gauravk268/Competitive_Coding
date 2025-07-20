class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;

        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        int sum = nums[0], tempSum = nums[0];
        
        for(int i=1; i<n; i++){
            tempSum = Math.max(nums[i], tempSum + nums[i]);
            sum = Math.max(sum, tempSum);
        }

        return sum;
    }
}