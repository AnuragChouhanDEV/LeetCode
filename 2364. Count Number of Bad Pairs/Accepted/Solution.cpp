// https://leetcode.com/problems/count-number-of-bad-pairs/description/

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool __boost = [](){
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

class Solution {
public:
typedef long long ll;
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> ma;

        int n = nums.size();
        ll total = (ll)n * (n - 1) / 2;

        for(int i = 0; i < n; ++i)
        {
            total -= ma[nums[i] - i];
            ma[nums[i] - i]++;
        }

        return total;
#if 0
        unordered_map<ll, ll> ma;
        ll res = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            ma[i-nums[i]]++;
        }

        ll total = (ll)n*(n-1)/2;
        ll good = 0;

        for (auto m:ma) {
            if (m.second > 1)
                good += m.second * (m.second-1) /2;
        }
        return total - good;
#endif
    }
};
/*
4 1 3 3
0 1 2 3
-------
-4, 0, -1, 0


*/