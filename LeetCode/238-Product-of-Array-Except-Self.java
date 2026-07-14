class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;

        int prod = 1;
        int countZero = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                countZero++;
            } else {
                prod = prod * nums[i];
            }
        }

        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            if (countZero == 0) {
                res[i] = prod / nums[i];
            } else if (countZero == 1 && nums[i] == 0) {
                res[i] = prod;
            }
        }

        return res;
    }
}