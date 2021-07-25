class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        int n=h.size();
        vector<int> result={0};
        stack<int> s;
        s.push(h[n-1]);

        for(int i=n-2; i>=0; i--){
            int count=0;
            while(s.size() && s.top()<h[i]){
                count++;
                s.pop();
            }

            if(s.empty())    result.push_back(count);
            else result.push_back(count+1);
            
            s.push(h[i]);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};