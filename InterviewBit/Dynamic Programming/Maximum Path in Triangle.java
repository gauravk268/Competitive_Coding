public class Solution 
{
    public int solve(ArrayList<ArrayList<Integer>> A) 
    {
        int ans=0;
        
        int n=A.size();
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0)
                {
                    int v=A.get(i).get(0);
                    A.get(i).set(0,v+A.get(i-1).get(0));
                }
                else
                {
                    int v1=A.get(i).get(j)+A.get(i-1).get(j);
                    int v2=A.get(i).get(j)+A.get(i-1).get(j-1);
                    int val=(int)(Math.max(v1,v2));
                    A.get(i).set(j,val);
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(A.get(n-1).get(i)>ans)
            {
                ans=A.get(n-1).get(i);
            }
        }
        
        return ans;
    }
}
