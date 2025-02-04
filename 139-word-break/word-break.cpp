class Solution {
    unordered_set<string> st;
    vector<vector<int>> dp;
    bool f(string s, int i, int j) {
        // base case
        if(i == s.size() && j == s.size()) return true;
        if(j == s.size()) return false;

        if(dp[i][j] != -1) {
            if(dp[i][j] == 1) return true;
            return false;
        }

        // not inc
        bool not_include = f(s, i, j+1);
        bool include = false;

        if(st.find(s.substr(i, j-i+1)) != st.end()) {
            include = f(s, j+1, j+1);
        }

        return dp[i][j] = not_include || include;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        dp.assign(n, vector<int> (n, -1));
        // -1 -> not vis
        // 0 -> returns false;
        // 1 -> returns true;
        for(auto& i : wordDict) st.insert(i);
        return f(s, 0, 0);        
    }
};