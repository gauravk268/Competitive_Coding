class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        if (n == 1)
            return 0;

        int i = 0, j = n-1, result = Integer.MIN_VALUE;
        while (i < j) {
            result = Math.max(result, (j - i) * Math.min(height[i], height[j]));
            
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }

        return result;

    }
}