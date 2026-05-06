1class StockSpanner {
2    Stack<int[]> stock;
3
4    public StockSpanner() {
5        stock = new Stack<>();
6    }
7
8    public int next(int price) {
9        int span = 1;
10        while(!stock.isEmpty() && stock.peek()[0] <= price){
11            span+=stock.pop()[1];
12        }
13        stock.add(new int[]{price, span});
14        return span;        
15    }
16}
17
18/**
19 * Your StockSpanner object will be instantiated and called as such:
20 * StockSpanner obj = new StockSpanner();
21 * int param_1 = obj.next(price);
22 */