class Solution {
    int calc_sum_of_digits(int num) {
        int sum = 0;
        while(num) {
            int d = num%10;
            num /= 10;
            sum += d;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int max_sum = -1;

        for(int num : nums) {
            int digit_sum = calc_sum_of_digits(num);

            if(mp.count(digit_sum)) {
                max_sum = max(max_sum, mp[digit_sum] + num);
            }

            mp[digit_sum] = max(mp[digit_sum], num);
        }

        return max_sum;
    }
};