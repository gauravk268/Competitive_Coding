public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public int isValidSudoku(final List<String> A) 
    {
        
        
        ArrayList<String> al=new ArrayList<String>();
        
        for(int i=0;i<3;i++)
        {
            StringBuffer s1=new StringBuffer();
            StringBuffer s2=new StringBuffer();
            StringBuffer s3=new StringBuffer();
            
            for(int j=3*i;j<(3*i+3);j++)
            {
                s1.append(A.get(0).charAt(j));
                s1.append(A.get(1).charAt(j));
                s1.append(A.get(2).charAt(j));
            }
            
            for(int j=3*i;j<(3*i+3);j++)
            {
                s2.append(A.get(3).charAt(j));
                s2.append(A.get(4).charAt(j));
                s2.append(A.get(5).charAt(j));
            }
            
            for(int j=3*i;j<(3*i+3);j++)
            {
                s3.append(A.get(6).charAt(j));
                s3.append(A.get(7).charAt(j));
                s3.append(A.get(8).charAt(j));
            }
            
            al.add(s1.toString());
            al.add(s2.toString());
            al.add(s3.toString());
            
        }
        
        for(int i=0;i<A.size();i++)
        {
            ArrayList<Character> t1=new ArrayList<Character>();
            ArrayList<Character> t2=new ArrayList<Character>();
            ArrayList<Character> t3=new ArrayList<Character>();
            
            for(int j=0;j<A.get(i).length();j++)
            {
                if(A.get(i).charAt(j)!='.')
                {
                    int v=A.get(i).charAt(j);
                    
                    if(v>=49 && v<=57)
                    {
                        if(t1.contains(A.get(i).charAt(j)))
                        {
                            return 0;
                        }
                        else
                        {
                            t1.add(A.get(i).charAt(j));
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
                
                if(al.get(i).charAt(j)!='.')
                {
                    int v=al.get(i).charAt(j);
                    
                    if(v>=49 && v<=57)
                    {
                        if(t2.contains(al.get(i).charAt(j)))
                        {
                            return 0;
                        }
                        else
                        {
                            t2.add(al.get(i).charAt(j));
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
                
                if(A.get(j).charAt(i)!='.')
                {
                    int v=A.get(j).charAt(i);
                    
                    if(v>=49 && v<=57)
                    {
                        if(t3.contains(A.get(j).charAt(i)))
                        {
                            return 0;
                        }
                        else
                        {
                            t3.add(A.get(j).charAt(i));
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
                
            }
        }
        
        
        return 1;
        
    }
}