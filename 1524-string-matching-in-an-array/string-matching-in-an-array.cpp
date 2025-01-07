class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {

        sort(words.begin(), words.end(), [](string& a, string& b){
            return a.size() < b.size();
        });

        int n = words.size();
        unordered_set<string> st;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(words[j].find(words[i]) != string::npos) {
                    st.insert(words[i]);
                    break;
                }
            }
        }

        return vector<string> (st.begin(), st.end());
    }
};