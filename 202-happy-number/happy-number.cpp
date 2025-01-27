class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        int cur_num = n;
        while(true) {
            int new_num = get_sum_of_square_of_digits(cur_num);
            if(new_num == 1) return true;
            if(st.count(new_num)) return false;
            st.insert(new_num);
            cur_num = new_num;
        }
        return true;
    }
private:
    int get_sum_of_square_of_digits(int n) {
        int sum = 0;
        while(n) {
            int x = n % 10;
            sum += (x*x);
            n /= 10;
        }
        return sum;
    }
};