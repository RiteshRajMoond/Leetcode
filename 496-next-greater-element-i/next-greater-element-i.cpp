class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int, int> mp;
        stack<int> st;

        for(int i = n2-1; i >= 0; i--) {
            while(!st.empty() && nums2[i] > st.top()) st.pop();
            if(!st.empty()) mp[nums2[i]] = st.top();
            else mp[nums2[i]] = -1;
            st.push(nums2[i]);
        }

        vector<int> res(n1);
        for(int i = 0; i < n1; i++) res[i] = mp[nums1[i]];
        return res;
    }
};