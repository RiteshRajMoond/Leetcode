#define ll long long

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        ll res = 0;
        vector<int> suff(n, 0);
        vector<int> preff(n, 0);

        preff[0] = nums[0];
        for(int i = 1; i < n; i++) {
            preff[i] = max(preff[i-1], nums[i]);
        }

        suff[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            suff[i] = max(suff[i+1], nums[i]);
        }

        for(int i = 1; i < n-1; i++) {
            res = max(res, (ll) (preff[i-1] - nums[i]) * suff[i+1]);
        }

        return res;
    }
};