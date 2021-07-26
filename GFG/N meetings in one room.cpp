class Solution{
    public:
    int maxMeetings(int start[], int end[], int n){
        vector<pair<int, int>> meet;
        
        for(int i=0; i<n; i++)  meet.push_back({start[i], end[i]});
        sort(meet.begin(), meet.end(), [](pair<int, int> &x , pair<int, int> &y ){return (x.second < y.second);});
        
        int count=1;
        int lastEnd=meet.front().second;

        for(int i=1; i<meet.size(); i++){
            if( meet[i].first > lastEnd ){
                count++;
                lastEnd = meet[i].second;
            }
        }
        
        return count;
    }
};