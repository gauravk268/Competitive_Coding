1class Solution {
2    public String reverseVowels(String s) {
3        int n=s.length();
4        char[] sb = s.toCharArray();
5        String vow = "aeiouAEIOU";
6
7        int i=0, j=n-1;
8        while(i<j){
9            while(i<j && vow.indexOf(sb[i])==-1){
10                i++;
11            }
12            while(i<j && vow.indexOf(sb[j])==-1){
13                j--;
14            }
15
16            char temp = sb[i];
17            sb[i]=sb[j];
18            sb[j]=temp;
19            i++;
20            j--;
21        }
22
23        return new String(sb);
24    }
25}