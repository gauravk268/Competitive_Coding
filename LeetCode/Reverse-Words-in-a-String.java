1class Solution {
2    public String reverseWords(String s) {
3        String[] words = s.split(" ");
4        StringBuilder sb = new StringBuilder();
5
6        for(int i=words.length-1; i>=0; i--){
7            if(!words[i].trim().isEmpty()){
8                sb.append(words[i].trim());
9                sb.append(" ");
10            }
11        }
12
13        return sb.toString().trim();
14    }
15}