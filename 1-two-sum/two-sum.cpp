class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) {
        vector<int> result(2);
        int n = nums.size();

        map<int, int> number_to_index_mapping;

        number_to_index_mapping[nums[0]] = 0;

        for (int i = 1; i < n; i++) {
            int cur_num = nums[i];
            int required_number = target - cur_num;

            if (number_to_index_mapping.count(required_number)) {
                result[0] = number_to_index_mapping[required_number];
                result[1] = i;
                break;
            }

            number_to_index_mapping[cur_num] = i;
        }

        return result;
    }
};