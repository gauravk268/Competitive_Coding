class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        priority_queue<int> pq;
        int k=((n+m)/2) +1;
        
        int result=0;
        if((n+m)&1)
        {
            for(int i=0; i<n; i++)
            {
                pq.push(nums1[i]);
                
                while(pq.size() > k)
                {
                    pq.pop();
                }
            }
            
            for(int i=0; i<m; i++)
            {
                pq.push(nums2[i]);
                
                while(pq.size() > k)
                {
                    pq.pop();
                }
            }
            
            return pq.top();
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                pq.push(nums1[i]);
                
                while(pq.size() > k)
                {
                    pq.pop();
                }
            }
            
            for(int i=0; i<m; i++)
            {
                pq.push(nums2[i]);
                
                while(pq.size() > k)
                {
                    pq.pop();
                }
            }
            
            int a=pq.top(); pq.pop();
            int b=pq.top();
            
            return (double)(a+b)/2.0;
        }
        
        return 0.0;
    }
};