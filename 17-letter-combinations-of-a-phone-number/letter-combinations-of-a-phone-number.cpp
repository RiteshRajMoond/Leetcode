class Solution {
    vector<string> res;
    map<char, vector<string>> mp;

    void generate_combinations(string& digits, int idx, string path) {
        if(idx == digits.size()) {
            if(path != "") res.push_back(path);
            return;
        }

        for(auto& j : mp[digits[idx]]) {
            generate_combinations(digits, idx+1, path + j);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        mp['2'] = {"a", "b", "c"};
        mp['3'] = {"d", "e", "f"};
        mp['4'] = {"g", "h", "i"};
        mp['5'] = {"j", "k", "l"};
        mp['6'] = {"m", "n", "o"};
        mp['7'] = {"p", "q", "r", "s"};
        mp['8'] = {"t", "u", "v"};
        mp['9'] = {"w", "x", "y", "z"};

        generate_combinations(digits, 0, "");
        return res;
    }
};