class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char& c : s) {
            mp[c]++;
        }

        vector<vector<char>> v(s.size()+1);
        for(auto& [ch, freq]: mp) {
            v[freq].push_back(ch);
        }

        string res = "";
        for(int i = s.size(); i >= 0; i--) {
            if(!v[i].empty()) {
                for(int j = 0; j < v[i].size(); j++) {
                    res.append(i, v[i][j]);
                }
            }
        }
        return res;
    }
};