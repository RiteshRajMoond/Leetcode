class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum_p = INT_MIN; // maximise
        int sum_n = INT_MAX; // minimise
        int cur = 0;

        for(int & i : nums) {
            cur += i;
            sum_p = max(sum_p, cur);
            if(cur < 0) cur = 0;
        }

        cur = 0;
        for(int& i : nums) {
            cur +=i;
            sum_n = min(sum_n, cur);
            if(cur > 0) cur = 0;
        }

        return max(sum_p, abs(sum_n));
    }
};