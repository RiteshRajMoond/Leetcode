class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), nums.end());
        int n = nums.size();

        queue<string> q;
        q.push("0");
        q.push("1");

        while(!q.empty()) {
            string ft = q.front();
            q.pop();

            if(ft.size() == n) {
                if(!st.count(ft)) return ft;
                continue;
            }

            for(char c : {'1', '0'}) {
                q.push(ft + c);
            }
        }
        return "";
    }
};