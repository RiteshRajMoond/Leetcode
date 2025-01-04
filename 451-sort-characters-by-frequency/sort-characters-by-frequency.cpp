class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char& c : s) {
            mp[c]++;
        }

        priority_queue< pair<int, char> >pq;
        for(auto& [ch, freq]: mp) {
            pq.push({freq, ch});
        }

        string res = "";
        while(!pq.empty()) {
            int n = pq.top().first;
            int ch = pq.top().second;
            pq.pop();
            res.append(n, ch);
        }
        return res;
    }
};