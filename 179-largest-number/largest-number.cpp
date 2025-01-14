class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int& a, int& b) {
            string ab = to_string(a) + to_string(b);
            string ba = to_string(b) + to_string(a);
            return ab > ba;
        });

        string res = "";
        for(auto& i : nums) res += to_string(i);
        
        if(res[0] == '0') return "0";
        return res;
        }
};