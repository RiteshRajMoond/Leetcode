class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> pref(n, 0);
        pref[0] = s[0]-'0';
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i-1] + (s[i]-'0');
        }

        int res = 0;
        for(int i = 1; i < n; i++) {
            int l = i - pref[i-1];
            int r = pref[n-1]-pref[i-1];
            res = max(res, l+r);
        }

        return res;
    }
};