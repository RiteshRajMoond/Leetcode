#define ll long long

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        ll res = LLONG_MAX;
        int n = grid[0].size();

        vector<ll> top(n+1, 0);
        vector<ll> bot(n+1, 0);

        for(int i = n-1; i >= 0; i--) {
            top[i] = top[i+1] + grid[0][i];
        }

        for(int i = 0; i < n; i++) {
            bot[i+1] = bot[i] + grid[1][i];
        }

        for(int i = 0; i < n; i++) {
            ll tp = top[i+1];
            ll bt = bot[i];

            ll cur_max = max(tp, bt);
            res = min(res, cur_max);
        }

        return res;
    }
};