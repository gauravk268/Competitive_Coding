class Solution {
    public int maxProfit(int[] prices) {
        int minValue = prices[0], resp=0;

        for(int i=1; i<prices.length; i++){
            if(prices[i] - minValue > resp)     resp = prices[i] - minValue;
            else if(minValue > prices[i]) minValue = prices[i];
        }

        return resp;
    }
}