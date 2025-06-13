class Solution {
    public boolean containsDuplicate(int[] nums) {
        if (nums.length < 2)
            return Boolean.FALSE;

        Set<Integer> set = new HashSet<>();

        for (int num : nums) {
            set.add(num);
        }

        return set.size() != nums.length;
    }
}