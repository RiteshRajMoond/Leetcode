#define ll long long
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp (high+1, -1);
        const int mod = 1e9+7;
        auto f = [&](auto& f, int sz) -> int {
            // base case
            if(sz > high) return 0;

            if(dp[sz] != -1) return dp[sz];

            int inc = (sz >= low && sz <= high) ? 1 : 0;

            ll on = f(f, sz+one);
            ll ze = f(f, sz+zero);

            return dp[sz] = (on + ze + inc) % mod;
        };

        return f(f, 0);
    }
};