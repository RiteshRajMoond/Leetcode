class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp; // char -> freq;
        int cnt = 0;
        int n = s.size();
        for (char& c : t)
            mp[c]++;
        int start_index = -1, min_len = INT_MAX;
        int i = 0, j = 0;
        while (j < n) {
            if (mp[s[j]] > 0)
                cnt++;
            mp[s[j]]--;

            if (cnt == t.size()) {
                // shrinking the window
                while (cnt == t.size()) {
                    if (j - i + 1 < min_len) {
                        start_index = i;
                        min_len = j - i + 1;
                    }
                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                        cnt--;
                    i++;
                }
            }
            j++;
        }

        return start_index == -1 ? "" : s.substr(start_index, min_len);
    }
};