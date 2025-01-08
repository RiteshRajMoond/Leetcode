class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            string s1 = words[i];

            for (int j = i + 1; j < n; j++) {
                string s2 = words[j];

                // Skip if s2 is shorter than s1
                if (s2.length() < s1.length()) 
                    continue;

                // Extract prefix and suffix
                string pre = s2.substr(0, s1.length());
                string suf = s2.substr(s2.length() - s1.length());

                // Check if both prefix and suffix match s1
                if (pre == s1 && suf == s1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};