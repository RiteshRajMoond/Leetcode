class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), m =  queries.size();
        vector<int> pref(n);

        pref[0] = (is_vowel(words[0].front()) && is_vowel(words[0].back())) ? 1 : 0;

        for(int i = 1; i < n; i++) {
            if(is_vowel(words[i].front()) && is_vowel(words[i].back())) pref[i] = pref[i-1] + 1;
            else pref[i] = pref[i-1];
        }

        vector<int> res;
        for(int i = 0; i < m; i++) {
            int l = queries[i][0], r = queries[i][1];
            if(l == 0) res.push_back(pref[r]);
            else res.push_back(pref[r] - pref[l-1]);
        }
        return res;
    }
private:
    bool is_vowel(const char& c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};