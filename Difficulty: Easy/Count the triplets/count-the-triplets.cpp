class Solution {
  public:
int countTriplet(vector<int>& arr) {
        int size = arr.size();
        sort(arr.begin(),arr.end());
        
        int count = 0;
        int sum = 0;
        
        //if size is less than 3
        if(size<3)
        {
            return 0;
        }
        
        int i = size-1;
        int left = 0;
        int right = 0;
        
        for (int i = size - 1; i >= 2; i--) {
            left = 0;
            right = i-1;
            while(left<right)
            {
                sum = arr[left] + arr[right];
                if(sum == arr[i]){
                    left++;
                    right--;
                    count++;
                }
                
                else if( sum > arr[i]){
                    right--;
                }
                else if(sum < arr[i]) {
                    left++;
                }
            }
        }
        return count;
    }
};