// https://leetcode.com/problems/design-bitset/description/

class Bitset {
public:
    string res;
    int size;
    int ones;
    bool flipped;
    Bitset(int size) {
        res.resize(size,'0');
        this->size = size;
        this->ones = 0;
        this->flipped = false;
    }
    
    void fix(int idx) {
        if (!flipped && res[idx] == '0') {
            res[idx] = '1';ones++;
        }
        if (flipped && res[idx] == '1') {
            res[idx] = '0';ones++;
        }
        
    }
    
    void unfix(int idx) {
        if (!flipped && res[idx] == '1') {
            res[idx] = '0';ones--;
        }
        if (flipped && res[idx] == '0') {
            res[idx] = '1';ones--;
        }
        
    }
    
    void flip() {
        flipped = !flipped;
        int zeros = size-ones;
        ones = zeros;
    }
    
    bool all() {
        return ones == size;
    }
    
    bool one() {
        return ones > 0;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        if (!flipped)
            return res;
        else {
            string ans = res;
            for (int i = 0; i < size; ++i) {
                ans[i] = (ans[i] == '1' ? '0' : '1');
            }
            return ans;
        }
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */