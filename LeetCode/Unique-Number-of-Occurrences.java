1class Solution {
2    public boolean uniqueOccurrences(int[] arr) {
3        Map<Integer, Integer> mp = new HashMap<>();
4
5        for (int i = 0; i < arr.length; i++) {
6            mp.put(arr[i], mp.getOrDefault(arr[i], 0) + 1);
7        }
8
9        int[] pos = new int[1001];
10        for(Integer key:mp.keySet()){
11            if (pos[mp.get(key)] == 1) {
12                return false;
13            }
14            pos[mp.get(key)] = 1;
15        }
16
17        return true;
18    }
19}