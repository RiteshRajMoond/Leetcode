class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int i = 0, j = 0, res = 0, max_freq = 0, n = s.size();

        while(j < n) {
            freq[s[j]-'A']++;
            max_freq = max(max_freq, freq[s[j]-'A']);

            while(j-i+1 - max_freq > k){
                freq[s[i]-'A']--;
                i++;
            }

            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};