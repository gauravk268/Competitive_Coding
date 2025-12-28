1class Solution {
2    public String mergeAlternately(String word1, String word2) {
3        String result = new String();
4        int i=0, j=0;
5        while(i<word1.length() || j<word2.length()){
6            if(result.length()%2 == 0 && i<word1.length()){
7                result = result + word1.charAt(i++);
8            }
9            else if(result.length()%2 == 1 && j<word2.length()){
10                result = result + word2.charAt(j++);
11            }
12            else if(i<word1.length()){
13                result = result + word1.charAt(i++);
14            }
15            else {
16                result = result + word2.charAt(j++);
17            }
18        }
19        return result;
20    }
21}