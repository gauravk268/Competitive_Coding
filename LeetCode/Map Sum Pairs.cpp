class MapSum {
public:
    /** Initialize your data structure here. */
    map<string, int> mp;
    
    MapSum() {
        mp.clear();
    }
    
    void insert(string key, int val) {
        mp[key]=val;
    }
    
    int sum(string prefix) {
        int count=0, n=prefix.length();
        for(auto &x:mp){
            if(x.first.substr(0, n)==prefix)    count+=x.second;
        }
        
        return count;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */