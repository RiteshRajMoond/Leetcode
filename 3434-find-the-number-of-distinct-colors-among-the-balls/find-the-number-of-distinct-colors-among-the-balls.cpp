class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> res;
        unordered_map<int, int> mp; // color -> freq
        unordered_set<int> st; // Contains our colored balls ;)
        // vector<int> colors(limit+1, -1); // store the color of the ball
        unordered_map<int, int> colors; // ball -> color

        for(auto& query : queries) {
            int ball = query[0];
            int color = query[1];

            // ball is not colored
            if(!st.count(ball)) {
                st.insert(ball);
                mp[color]++;
                colors[ball] = color;
            } else {
                int cur_color = colors[ball];
                mp[cur_color]--;
                if(mp[cur_color] == 0) mp.erase(cur_color);
                mp[color]++;
                colors[ball] = color;
            }
            res.push_back(mp.size());
        }
        return res;
    }
};