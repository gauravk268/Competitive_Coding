class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int l1 = str1.length(), l2 = str2.length();

        if (!(str1 + str2).equals(str2 + str1)) {
            return "";
        }

        return str1.substring(0, gcd(l1, l2));
    }

    private int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
}