class Solution {
public:
    string removeOccurrences(string s, string part) {
        string final_string = "";
        int part_len = part.size();

        for (char c : s) {
            final_string.push_back(c);
            if (final_string.size() >= part_len &&
                final_string.substr(final_string.size() - part_len) == part)
                final_string.erase(final_string.size() - part_len);
        }

        return final_string;
    }
};