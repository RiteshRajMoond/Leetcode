#define ll long long

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> arr;
        for(auto& i : grid) {
            for(int j : i) 
                arr.push_back(j);
        }

        int cur_sum = accumulate(arr.begin(), arr.end(), 0);
        int n = arr.size() ;
        int og_sum = (n * (n+1)) / 2;

        int m_minus_r = og_sum - cur_sum; // --- [1]

        ll og2_sum = (1LL * n*(n+1)*(2*n+1))/6;
        ll cur2_sum = 0;
        for(int i : arr) {
            int sq = i*i*1LL;
            cur2_sum += sq;
        }

        int m2_minus_r2 = og2_sum - cur2_sum;

        int m_plus_r = m2_minus_r2/m_minus_r; // --- [2]

        int m = (m_minus_r + m_plus_r)/2;
        int r = m_plus_r - m;

        return {r, m};
    }
};