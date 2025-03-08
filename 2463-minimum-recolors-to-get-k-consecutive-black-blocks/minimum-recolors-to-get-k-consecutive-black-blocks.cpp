class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int recolors = INT_MAX, cur = 0;
        int n = blocks.size();
        int i = 0, j = 0;

        while(j < n) {
            if(blocks[j] == 'W') cur++;
            j++;
            if(j-i == k) {
                recolors = min(recolors, cur);
                if(blocks[i] == 'W') cur--;
                i++;
            }
        }

        return recolors;
    }
};