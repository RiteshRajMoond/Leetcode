class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        const int mod = 1e9+7;
        int pref_sum = 0;
        int odd_c = 0, even_c = 1;
        int subarrays = 0;
        for(int& num : nums) {
            pref_sum += num;
            if(pref_sum&1) {
                subarrays = (subarrays + even_c) % mod;
                odd_c++;
            } else {
                subarrays = (subarrays + odd_c) % mod;
                even_c++;
            }
        } 
        return subarrays;
    }
};