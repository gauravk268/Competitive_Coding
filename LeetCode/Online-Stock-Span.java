1class StockSpanner {
2    List<Integer> stock;
3
4    public StockSpanner() {
5        stock = new ArrayList<>();
6    }
7
8    public int next(int price) {
9        int result = 1;
10        for (int i = stock.size() - 1; i >= 0; i--) {
11            if (stock.get(i) <= price) {
12                result++;
13            } else
14                break;
15        }
16        stock.add(price);
17        return result;
18    }
19}
20
21/**
22 * Your StockSpanner object will be instantiated and called as such:
23 * StockSpanner obj = new StockSpanner();
24 * int param_1 = obj.next(price);
25 */