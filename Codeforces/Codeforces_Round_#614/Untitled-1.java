import java.util.*;
import java.lang.*;
import java.util.Arrays;
public class Main {
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        ArrayList<Long> al=new ArrayList<Long>();
        
        while(t>0)
        {
            long n=sc.nextLong();
            long s=sc.nextLong();
            int k=sc.nextInt();

            long[] arr=new long[k];

            for(int i=0;i<k;i++)
            {
                arr[i]=sc.nextLong();
                al.add(arr[i]);
            }

            Arrays.sort(arr);

            long x=s;
            long y=s;
            long ans=s;

            int c1=0,c2=0;

            while(c1==0 && c2==0)
            {
                int pos1=Arrays.binarySearch(arr,x);
                int pos2=Arrays.binarySearch(arr,y);

                if(pos1<0 && x<=n)
                {
                    ans=x-s;
                    break;
                }

                
                if(pos2<0 && y>=1)
                {
                    ans=s-y;
                    break;
                }

                x++;
                y--;

            }

            System.out.println(ans);
            t--;


        }

        
  }
}