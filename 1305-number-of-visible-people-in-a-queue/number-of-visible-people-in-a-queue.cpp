class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> res(n, 0);

        for(int i = n-1; i >= 0; i--) {
            int cnt = 0;

            while(!st.empty() && heights[st.top()] < heights[i]) {
                st.pop();
                cnt++;
            }

            if(!st.empty()) cnt++;
            res[i] = cnt;
            st.push(i);
        }

        return res;
    }
};