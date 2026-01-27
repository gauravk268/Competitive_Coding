1/** 
2 * Forward declaration of guess API.
3 * @param  num   your guess
4 * @return 	     -1 if num is higher than the picked number
5 *			      1 if num is lower than the picked number
6 *               otherwise return 0
7 * int guess(int num);
8 */
9
10public class Solution extends GuessGame {
11    public int guessNumber(int n) {
12        int low = 1, high = n;
13
14        while (low <= high) {
15            int mid = low + (high - low) / 2;
16            if (guess(mid) == -1) {
17                high = mid - 1;
18            } else if (guess(mid) == 1) {
19                low = mid + 1;
20            }
21            else{
22                return mid;
23            }
24        }
25
26        return -1;
27    }
28}