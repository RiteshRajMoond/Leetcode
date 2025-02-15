class Solution {
    bool is_valid(string num_str, const int& target, int sum = 0) {
        if(num_str.empty()) return sum == target;

        for(int i = 1; i <= num_str.size(); i++) {
            int part = stoi(num_str.substr(0, i));
            if(is_valid(num_str.substr(i), target, sum + part)) return true;
        }
        return false;
    }
public:
    int punishmentNumber(int n) {
        int punishment = 0;

        for(int i = 1; i <= n; i++) {
            if(is_valid(to_string(i*i), i)) punishment += i*i;
        }

        return punishment;
    }
};