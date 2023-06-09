// https://leetcode.com/problems/design-underground-system

class UndergroundSystem {
public:
    unordered_map<int, pair<string,int>> cust;
    unordered_map<string, pair<int,int>> sta;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        cust[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        if (cust.find(id) != cust.end()) {
            string str = cust[id].first+"to"+stationName;
            //cout << str << endl;
            if (sta.find(str) == sta.end()) {
                //cout << "was here" <<endl;
                sta[str] = {t-cust[id].second, 1};
            }
            else {
                int count = sta[str].second;
                //cout << "now here" <<endl;
                sta[str] = {t-cust[id].second+sta[str].first, count+1};
            }
        }
        cust.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string str = startStation+"to"+endStation;
        //cout << "avg" << str << endl;
        //cout<< endl;
        return (double) sta[str].first / (double) sta[str].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */