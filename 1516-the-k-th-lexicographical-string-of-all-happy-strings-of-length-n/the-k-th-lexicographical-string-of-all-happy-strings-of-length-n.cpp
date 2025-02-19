class Solution {
public:
    string getHappyString(int n, int k) {
        queue<string> q;
        q.push("a");
        q.push("b");
        q.push("c");
        vector<string> happy_strings;

        while(!q.empty()) {
            string cur = q.front();
            q.pop();

            if(cur.size() == n) {
                happy_strings.push_back(cur);
                continue;
            }

            for(char ch : {'a', 'b', 'c'}) {
                if(cur.back() != ch) {
                    q.push(cur + ch);
                }
            }
        }

        return (happy_strings.size() < k) ? "" : happy_strings[k-1];
    }
};