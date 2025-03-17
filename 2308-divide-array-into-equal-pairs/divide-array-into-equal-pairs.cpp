class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int& i : nums) {
            if(mp.count(i)) mp.erase(i);
            else mp[i]++;
        }

        return mp.size() == 0;
    }
};