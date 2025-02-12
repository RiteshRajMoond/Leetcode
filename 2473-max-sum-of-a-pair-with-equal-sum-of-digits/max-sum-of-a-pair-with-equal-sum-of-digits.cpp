class Solution {
    unordered_map<int, multiset<int>> mp; // sum -> indices;
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
        for(int& num : nums) {
            int sum_of_digits = calc_sum_of_digits(num);
            mp[sum_of_digits].insert(num);
        }

        int max_sum = -1;
        for(auto& [sum, numbers]: mp) {
            int n = numbers.size();
            if(n <= 1) continue;
            auto num1 = numbers.begin(), num2 = numbers.begin();
            advance(num1, n-1);
            advance(num2, n-2);
            max_sum = max(max_sum, *num1 + *num2);
        }
        return max_sum;
    }
};