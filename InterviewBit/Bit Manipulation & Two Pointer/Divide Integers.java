public class Solution {
    
    public int divide(int A, int B) 
    {
        long v1=A;
        long v2=B;
        long ans=v1/v2;
        
        if(ans>Integer.MAX_VALUE || ans<Integer.MIN_VALUE)
        {
            return Integer.MAX_VALUE;
        }
        else
        {
            return (int)ans;
        }
    }
}
