#define ll long long
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp (high+1, -1);
        const int mod = 1e9+7;

        for(int sz = high; sz >= 0; sz--) {
            int inc = (sz >= low && sz <= high) ? 1 : 0;
            ll on = (sz + one <= high) ? dp[sz+one] : 0;
            ll ze = (sz + zero <= high) ? dp[sz+zero] : 0;
            dp[sz] = (on+ze+inc)%mod;
        }

        return dp[0];
    }
};