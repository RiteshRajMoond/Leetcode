class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;
        vector<double> res;
        
        for(int& i : arr) {
            left.push(i);
            if(left.size() == right.size()+2) {
                right.push(left.top());
                left.pop();
            }
            
            if(right.size() != 0 && left.top() > right.top()) {
                int lft = left.top(); left.pop();
                int rgt = right.top(); right.pop();
                
                left.push(rgt);
                right.push(lft);
            }
            
            int total_size = left.size() + right.size();
            if(total_size&1) {
                res.push_back(left.top());
            } else {
                double median = (left.top() + right.top()) / 2.0;
                res.push_back(median);
            }
        }
        
        return res;
    }
};
