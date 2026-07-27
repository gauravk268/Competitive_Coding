class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        int[] count = new int[2002];
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] < 0) {
                count[2000 + arr[i]]++;
            } else {
                count[arr[i]]++;
            }
        }

        int[] freq = new int[1001];
        for (int i = 0; i < 2002; i++) {
            if (count[i] != 0 && freq[count[i]] == 1) {
                return false;
            }

            freq[count[i]] = 1;
        }

        return true;
    }
}