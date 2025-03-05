class Solution {
public:
    bool checkPowersOfThree(int n) {
        int limit = log(n)/log(3);
        int cur_sum = 0;

        while(limit >= 0) {
            int num = pow(3, limit);
            if(cur_sum+num == n) return true;
            else if (cur_sum + num < n) cur_sum += num;
            limit--;
        }

        return false;
    }
};