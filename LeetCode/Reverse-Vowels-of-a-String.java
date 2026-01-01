1class Solution {
2    public Boolean isVowel(char s){
3        return List.of('a', 'e', 'i', 'o', 'u').contains(Character.toLowerCase(s));
4    }
5
6    public String reverseVowels(String s) {
7        Queue<Integer> q=new LinkedList<>();
8        int n=s.length();
9        StringBuilder sb = new StringBuilder(s);
10
11        int j=n-1;
12        for(int i=0; i<n; i++){
13            if(isVowel(s.charAt(i))){
14                while(j>=i && !isVowel(s.charAt(j))){
15                    j--;
16                }
17
18                if(j>i){
19                    sb.setCharAt(i, s.charAt(j));
20                    sb.setCharAt(j, s.charAt(i));
21                    j--;
22                }
23            }
24        }
25
26        return sb.toString();
27    }
28}