class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;

        for (auto& file : folder) {
            if (ans.empty() ||
                file.substr(0, ans.back().size()) != ans.back() ||
                file[ans.back().size()] != '/')
                ans.push_back(file);
        }
        return ans;
    }
};