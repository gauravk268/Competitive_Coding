1
2class Solution {
3    public long totalCost(int[] costs, int k, int candidates) {
4        int n = costs.length;
5        long result = 0;
6
7        PriorityQueue<Integer> q_front = new PriorityQueue<>(), q_back = new PriorityQueue<>();
8
9        int i = 0, j = n - 1;
10
11        for (int count = 0; count < candidates && i <= j; count++) {
12            q_front.add(costs[i++]);
13        }
14        for (int count = 0; count < candidates && j >= i; count++) {
15            q_back.add(costs[j--]);
16        }
17
18        while (k-- > 0) {
19            int leftMin = q_front.isEmpty() ? Integer.MAX_VALUE : q_front.peek();
20            int rightMin = q_back.isEmpty() ? Integer.MAX_VALUE : q_back.peek();
21
22            if (leftMin <= rightMin) {
23                result += q_front.poll();
24                if (i <= j) {
25                    q_front.add(costs[i++]);
26                }
27            } else {
28                result += q_back.poll();
29                if (i <= j) {
30                    q_back.add(costs[j--]);
31                }
32            }
33        }
34
35        return result;
36    }
37}
38