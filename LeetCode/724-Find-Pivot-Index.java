class Solution {
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int temp = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                temp += nums[i - 1];
            }

            if (temp*2 == sum-nums[i]) {
                return i;
            }
        }

        return -1;
    }
}