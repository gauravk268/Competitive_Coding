class MyCalendar {
public:
    vector<pair<int, int>> cal;
    MyCalendar() {
        cal.clear();
    }
    
    bool book(int start, int end) {
        for(auto x:cal){
            if(!(x.second <= start && x.second<end) && !(x.first > start && x.first>=end))  return false;
        }
        
        cal.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */