class Solution {
public:
    int findCircleNum(vector<vector<int>>& con) {
        int n = con.size();
        unordered_set<int> st;

        auto dfs = [&](auto& self, int cur) -> void {
            st.insert(cur);
            for(int i = 0; i < n; i++) {
                if(cur != i && con[cur][i] == 1 && !st.count(i)) self(self, i);
            }
        };

        int res = 0;
        for(int i = 0; i < n; i++) {
            if(!st.count(i)) {
                res++;
                dfs(dfs, i);
            }
        }

        return res;
    }
};