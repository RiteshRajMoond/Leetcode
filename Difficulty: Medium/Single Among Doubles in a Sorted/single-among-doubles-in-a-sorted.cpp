class Solution {
  public:
    int findOnce(vector<int>& arr) {
        // code here.
        int l = 0, r = arr.size()-1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(mid > 0 && arr[mid] == arr[mid-1]) mid--;
            
            if(mid&1) r = mid-1;
            else l = mid+2;
        }
        
        return arr[l-2];
    }
};