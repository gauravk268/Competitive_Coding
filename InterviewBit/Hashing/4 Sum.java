public class Solution {
    public ArrayList<ArrayList<Integer>> fourSum(ArrayList<Integer> A, int B) 
    {
        ArrayList<ArrayList<Integer>> ans=new ArrayList<ArrayList<Integer>>();
        
        Collections.sort(A);
        
        for(int i=0;i<A.size();i++)
        {
            int v1=B-A.get(i);
            
            for(int j=i+1;j<A.size();j++)
            {
                int v2=v1-A.get(j);
                
                int k1=j+1;
                int k2=A.size()-1;
                
                while(k1<k2)
                {
                    if((A.get(k1)+A.get(k2))==v2)
                    {
                        ArrayList<Integer> tmp=new ArrayList<Integer>();
                        tmp.add(A.get(i));
                        tmp.add(A.get(j));
                        tmp.add(A.get(k1));
                        tmp.add(A.get(k2));
                        
                        ans.add(tmp);
                        
                        int v=A.get(k1);
                        
                        while(A.get(k1)==v)
                        {
                            k1++;
                            
                            if(k1>=k2)
                            {
                                break;
                            }
                        }
                    }
                    else
                    {
                        if((A.get(k1)+A.get(k2))<v2)
                        {
                            int v=A.get(k1);
                            
                            while(A.get(k1)==v)
                            {
                                k1++;
                                
                                if(k1>=k2)
                                {
                                    break;
                                }
                            }
                        }
                        else
                        {
                            int v=A.get(k2);
                            
                            while(A.get(k2)==v)
                            {
                                k2--;
                                
                                if(k1>=k2)
                                {
                                    break;
                                }
                            }
                        }
                    }
                    
                    
                    
                }
            
                
                
            }
        }
        
        ArrayList<ArrayList<Integer>> ans1=new ArrayList<ArrayList<Integer>>();
        
        for(int i=0;i<ans.size();i++)
        {
            if(ans1.contains(ans.get(i))==false)
            {
                ans1.add(ans.get(i));
            }
        }
        
        return ans1;
    }
}