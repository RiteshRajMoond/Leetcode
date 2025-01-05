class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> pref(n+1, 0);
        for(auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int dir = (shift[2] == 1) ? 1 : -1;

            pref[start] += dir;
            pref[end+1] -= dir;
        }

        for(int i = 1; i < n; i++) {
            pref[i] += pref[i-1];
        }

        for(int i = 0; i < n; i++) {
            int shift = (pref[i]%26+26)%26;
            s[i] = 'a' + (-'a'+s[i]+shift)%26;
        }
        
        return s;
    }
};