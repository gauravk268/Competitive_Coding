class Solution {
    public int compress(char[] chars) {
        int n = chars.length;

        int k = 0, count = 1;
        char prev = chars[0], curr = chars[0];
        for (int i = 1; i < n; i++) {
            curr = chars[i];
            if (curr != prev) {
                chars[k++] = prev;
                if (count > 1) {
                    for (char c : String.valueOf(count).toCharArray()) {
                        chars[k++] = c;
                    }
                }
                prev = curr;
                count=1;
            } else {
                count++;
            }
        }

        chars[k++] = curr;
        if (count > 1) {
            for (char c : String.valueOf(count).toCharArray()) {
                chars[k++] = c;
            }
        }

        return k;
    }
}