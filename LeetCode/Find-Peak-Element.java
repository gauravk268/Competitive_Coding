1class Solution {
2    public int findPeakElement(int[] nums) {
3        int n = nums.length;
4
5        if (n == 1 || nums[1] < nums[0]) {
6            return 0;
7        } else if (nums[n - 1] > nums[n - 2]) {
8            return n - 1;
9        }
10
11        int low = 1, high = n - 2;
12        while (low <= high) {
13            int mid = low + (high - low) / 2;
14            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
15                return mid;
16            }
17
18            if (nums[mid] < nums[mid - 1])
19                high = mid - 1;
20            else if (nums[mid] < nums[mid + 1])
21                low = mid + 1;
22        }
23
24        return -1;
25    }
26}