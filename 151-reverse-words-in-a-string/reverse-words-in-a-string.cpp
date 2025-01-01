class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> words;
        while(ss >> s) {
            words.push_back(s);
        }
        string res;
        for (auto it = words.rbegin(); it != words.rend(); ++it) {
            if (!res.empty()) {
                res += " "; 
            }
            res += *it;
        }

        return res;
    }
};