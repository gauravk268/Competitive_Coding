class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > min_heap;
        
        int n=dist.size(), tp=0;
        for(int i=0; i<n; i++){
            int k=ceil((double)dist[i]/(double)speed[i]);            
            min_heap.push({k, dist[i]});
        }
        
        int count=0, time=0;
        if(min_heap.top().first<=0){
            count=1;
        }else{
            while(!min_heap.empty()){
                pair<int, int> mon=min_heap.top();
                min_heap.pop();

                if(mon.first==0)   break;

                if( mon.first > time){
                    count++;
                }else break;

                time++;
            }
        }
        
        return count;
    }
};