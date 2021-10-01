public class Solution {
    
    int calc(int n)
    {
        int f=1;
        while(n>0)
        {
            f=f*(n%10);
            n=n/10;
        }
        return f; 
    }
    public int colorful(int A) 
    {
        int tmp=A;
        
        int c=0;
        while(tmp>0)
        {
            tmp=tmp/10;
            c++;
        }
        
        ArrayList<Integer> al=new ArrayList<Integer>();
        
        tmp=1;
        int k=c;
        
        while(tmp<=k)
        {
            for(int i=0;i<c;i++)
            {
                int v=(A/(int)Math.pow(10,i));
                
                int v1=v%(int)Math.pow(10,tmp);
                int p=calc(v1);
                
                if(al.contains(p)==true)
                {
                    return 0;
                }
                
                al.add(p);
            }
            
            tmp++;
            c--;
        }
        
        return 1;
    }
}
