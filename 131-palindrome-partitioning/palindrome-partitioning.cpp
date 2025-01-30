class Solution {
    vector<vector<string>> res;
    vector<string> path;
    
    bool is_palindrome(string& s) {
        int l = 0, r = s.size()-1;
        while(l < r) {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }

    void palindrome_partition(string& s, int idx) {
        if(idx == s.size()) {
            res.push_back(path);
            return;
        }

        for(int i = idx; i < s.size(); i++) {
            string sub = s.substr(idx, i-idx+1);
            if(is_palindrome(sub)) {
                path.push_back(sub);
                palindrome_partition(s, i+1);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        palindrome_partition(s, 0);
        return res;
    }
};