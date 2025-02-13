class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 1) return 1;

        vector<int> candies(n);
        if(ratings[0] > ratings[1]) candies[0] = 2;
        else candies[0] = 1;

        // ltr
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i-1]) candies[i] = candies[i-1]+1;
            else candies[i] = 1;
        }

        // rtl
        for(int i = n-2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]) candies[i] = candies[i+1]+1;
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};