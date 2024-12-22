class Solution {
public:
    int findCircleNum(vector<vector<int>>& isCon) {
        int n = isCon.size();
        unordered_set<int> st;

        auto bfs = [&](int cur) -> void {
            queue<int> q;
            q.push(cur);
            st.insert(cur);

            while (!q.empty()) {
                int ft = q.front();
                q.pop();

                for (int i = 0; i < n; i++) {
                    if (i != ft && isCon[ft][i] == 1 && !st.count(i)) {
                        st.insert(i);
                        q.push(i);
                    }
                }
            }
        };

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!st.count(i)) {
                res++;
                bfs(i);
            }
        }
        return res;
    }
};