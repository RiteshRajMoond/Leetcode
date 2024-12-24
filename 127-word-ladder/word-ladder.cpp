class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(), wordList.end());

        if(st.count(endWord) == 0) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()) {
            auto ft = q.front();
            q.pop();
            string s = ft.first;
            for(int i = 0; i < s.size(); i++) {
                for(char c = 'a'; c <= 'z'; c++) {
                    string temp = s;
                    temp[i] = c;
                    if(temp == endWord) return ft.second+1;
                    if(st.count(temp)) {
                        q.push({temp, ft.second+1});
                        st.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};