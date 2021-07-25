class Solution {
public:
    int smallestChair(vector<vector<int>>& time, int t) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        set<int> s;

        int sTime=time[t][0];
        sort(time.begin(), time.end());
        int i=0;
        for(auto &x:a){
            int at=x[0], lt=x[1];
            int cs;

            while(pq.size() && pq.top().first <= at){
                s.insert(pq.top().second);
                pq.pop();
            }

            if(s.empty()){
                cs=i;
                i++;
            }else{
                cs=*(s.begin());
                s.erase(s.begin());
            }

            pq.push({lt, cs});
            if(at==sTime){
                return cs;
            }
        }

        return 0;
    }
};