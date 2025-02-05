class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        int n = s1.size();
        vector<int> diff;
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                cnt++;
                diff.push_back(i);
            }
        }

        return (cnt == 0 || (cnt == 2 && (s1[diff[0]] == s2[diff[1]]) && (s1[diff[1]] == s2[diff[0]]) )) ? true : false;
    }
};