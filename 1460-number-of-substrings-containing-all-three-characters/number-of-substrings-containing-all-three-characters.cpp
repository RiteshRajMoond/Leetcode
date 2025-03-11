class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), res = 0;
        vector<int> last(3, -1);

        for(int i = 0; i < n; i++) {
            last[s[i]-'a'] = i;
            if(last[0] != -1 && last[1] != -1 && last[2] != -1) {
                res += (1 + min({last[0], last[1], last[2]}));
            }
        }

        return res;
    }
};