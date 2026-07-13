class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int l = flowerbed.length;

        for (int i = 0; i < l; i++) {
            if (flowerbed[i] == 1) {
                i++;
            } else if (i < l - 1 && flowerbed[i + 1] == 0 || i == l - 1) {
                n--;
                i++;
            }
        }

        return (n <= 0);
    }
}