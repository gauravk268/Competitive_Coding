1class Solution {
2    private boolean isVow(char a){
3        String vow = "aeiou";
4        return vow.indexOf(a) != -1;
5    }
6    public int maxVowels(String s, int k) {
7        int n=s.length(), sum=0, tempSum=0;
8        int i=0, j=0;
9
10        while(i<n){
11            if(i<k){
12                if(isVow(s.charAt(i))){
13                    tempSum++;
14                }
15            }
16            else{
17                if(isVow(s.charAt(i))){
18                    tempSum++;
19                }
20                if(isVow(s.charAt(j))){
21                    tempSum--;
22                }
23                j++;
24            }
25
26            i++;
27            if(i>=k){
28                sum = Math.max(sum, tempSum);
29            }
30        }
31
32        return sum;
33    }
34}