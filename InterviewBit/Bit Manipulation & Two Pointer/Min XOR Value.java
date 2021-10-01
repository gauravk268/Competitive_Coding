public class Solution {
    public int findMinXor(ArrayList<Integer> A) 
    {
        int min=Integer.MAX_VALUE;
        Collections.sort(A);
        
        
            for(int j=0;j<A.size()-1;j++)
            {
                int tmp=A.get(j+1)^A.get(j);
                
                if(tmp<min)
                {
                    min=tmp;
                }
            }
        
        
        return min;
    }
}
