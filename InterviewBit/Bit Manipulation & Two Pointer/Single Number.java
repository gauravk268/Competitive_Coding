public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public int singleNumber(final List<Integer> A) 
    {
        int x=A.get(0);
        
        for(int i=1;i<A.size();i++)
        {
            x=x^A.get(i);
        }
        
        return x;
    }
}
