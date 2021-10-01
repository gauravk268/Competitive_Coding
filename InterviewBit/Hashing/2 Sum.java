public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public ArrayList<Integer> twoSum(final List<Integer> A, int B) 
    {
        ArrayList<Integer> ans=new ArrayList<Integer>();
        HashMap<Integer,Integer> hm=new HashMap<Integer,Integer>();
        
        for(int i=0;i<A.size();i++)
        {
            if(hm.containsKey(A.get(i))==false)
            {
                hm.put(A.get(i),i+1);
            }
        }
        
        int v3=A.size()+1,v4=A.size()+1;
        
        for(int i=0;i<A.size();i++)
        {
            if(hm.containsKey(B-A.get(i))==true)
            {
                int v1=i+1;
                int v2=hm.get(B-A.get(i));
                
                if(v1!=v2)
                {
                    if(v1>v2)
                    {
                        if(v1<v4)
                        {
                            v4=v1;
                            v3=v2;
                        }
                        
                    }
                    else
                    {
                        if(v2<v4)
                        {
                            v4=v2;
                            v3=v1;
                        }
                    }
                }
                
            }
        }
        
        if(v4!=(A.size()+1))
        {
            ans.add(v3);
            ans.add(v4);
        }
        
        return ans;
    }
}