class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candies = 1, i = 1;
        while (i < n) {
            if (ratings[i - 1] == ratings[i]) {
                i++;
                candies++;
                continue;
            }

            // ascent
            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                candies += peak;
                i++;
            }

            // descent
            int down = 1;
            while (i < n && ratings[i] < ratings[i - 1]) {
                candies += down;
                down++;
                i++;
            }

            if (down > peak)
                candies += (down - peak);
        }
        return candies;
    }
};