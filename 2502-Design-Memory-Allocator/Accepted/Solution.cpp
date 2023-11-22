// https://leetcode.com/problems/design-memory-allocator/description/

class Allocator {
       // block, size
    map<int, int> freeInd2Size; // for free memory
                // mID            // block, size
    unordered_map<int, vector<pair<int, int>>> mID2ListOfPairsOfIndSize; // for allocated memory

public:
    Allocator(int n) {
        freeInd2Size.insert({0, n});
    }
    
    int allocate(int size, int mID) {
        for (auto& e : freeInd2Size) {
            int i = e.first; // index of `free block`
            int s = e.second; // size of `free block`
            if (size <= s) {
                // found
                mID2ListOfPairsOfIndSize[mID].push_back({i, size});
                if (s > size) {
                    freeInd2Size.insert({i + size, s - size});
                }
                freeInd2Size.erase(i);
                return i;
            }
        }
        // not found
        return -1;
    }
    
    int free(int mID) {
        int freeMemoryCount = 0;

        // ------ the key here is to update the freeInd2Size ------
        for (const auto& pair : mID2ListOfPairsOfIndSize[mID]) {
            int i = pair.first; // index of `block to be released`
            int s = pair.second; // size of `block to be released`
            auto it = freeInd2Size.insert({i, s}).first; // get the iterator pointing to the inserted element

            // update the memory location due to continuous block
            if (it != freeInd2Size.begin()) {
                auto prevIt = prev(it);
                // check if left continueos
                if (prevIt->first + prevIt->second == i) {
                    prevIt->second += s;
                    freeInd2Size.erase(it);
                    it = prevIt;
                }
            }
            if (next(it) != freeInd2Size.end()) {
                auto nextIt = next(it);
                // check right continueos
                if (i + s == nextIt->first) {
                    it->second += nextIt->second;
                    freeInd2Size.erase(nextIt);
                }
            }

            freeMemoryCount += s;
        }
        mID2ListOfPairsOfIndSize.erase(mID);
        return freeMemoryCount;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */