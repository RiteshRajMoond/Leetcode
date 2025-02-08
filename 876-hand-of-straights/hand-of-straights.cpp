class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize) return false;
        unordered_map<int, int> mp;
        for(int& num : hand) {
            mp[num]++;
        }

        sort(hand.begin(), hand.end());

        for(int num : hand) {
            if(mp[num] > 0) {
                for(int i = 0; i < groupSize; i++) {
                    if(mp[num+i] == 0) return false;
                    mp[num+i]--;
                }
            }
        }

        return true;
    }
};