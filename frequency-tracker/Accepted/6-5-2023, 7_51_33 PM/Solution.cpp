// https://leetcode.com/problems/frequency-tracker

class FrequencyTracker {
public:
    unordered_map<int,int> ma;
    unordered_map<int,int> freq;
    FrequencyTracker() {
        ma.clear();
        freq.clear();
    }
    
    void add(int number) {
        if (freq.find(ma[number]) != freq.end()) {
            freq[ma[number]]--;
            if (freq[ma[number]] == 0)
                freq.erase(ma[number]);
        }
        ma[number]++;
        freq[ma[number]]++;
    }
    
    void deleteOne(int number) {
        if (ma.find(number) != ma.end()) {
            if (freq.find(ma[number]) != freq.end()) {
                freq[ma[number]]--;
                if (freq[ma[number]] == 0)
                    freq.erase(ma[number]);
            }
            ma[number]--;
            if (ma[number] == 0)
                ma.erase(number);
            else
                freq[ma[number]]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        if (freq.find(frequency) != freq.end())
            return true;
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */