class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candies = 1;
        int i = 1;

        while(i < n) {
            if(ratings[i] == ratings[i-1]) {
                candies++;
                i++;
                continue;
            }

            // calculating peak
            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]) {
                i++;
                peak++;
                candies += peak;
            }

            // calculating descent
            int down = 1;
            while(i < n && ratings[i] < ratings[i-1]) {
                i++;
                candies += down;
                down++;
            }

            if(down > peak) candies += (down - peak);
        }

        return candies;        
    }
};