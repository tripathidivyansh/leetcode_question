class MyCalendar {
public:
    MyCalendar() {
        
    }
    vector<pair<int,int>>events;
    bool book(int startTime, int endTime) {
        for(auto &event : events){
            if(startTime < event.second && endTime > event.first){
                return false;
            }
        }
        events.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */