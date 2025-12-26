1class Solution {
2    public boolean isHappy(int n) {
3        HashMap<Integer, Boolean> flag = new HashMap<>();
4
5        while(flag.get(n) == null){
6            if(n == 1)  return true;
7            flag.put(n, true);
8            n = numSquare(n);
9            // System.out.printf("%d\n", n);
10        }
11
12        return false;
13    }
14
15    private Integer numSquare(int n){
16        Integer res=0;
17
18        while(n != 0){
19            res = res + (n%10)*(n%10);
20            n = n/10;
21        }
22
23        return res;
24    }
25}