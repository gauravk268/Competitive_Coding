class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        if (n == 1)
            return 0;

        int i = 0, j = n - 1, result = Integer.MIN_VALUE, minHeight = Integer.MIN_VALUE;
        while (i < j) {
            minHeight = Math.min(height[i], height[j]);
            result = Math.max(result, (j - i) * minHeight);

            while (i < j && minHeight >= height[i])
                i++;
            while (i < j && minHeight >= height[j])
                j--;
        }

        return result;

    }
}