class Solution {
    public boolean containsDuplicate(int[] nums) {
        if (nums.length < 2)
            return false;

        Map<Integer, Integer> freqMap = new TreeMap<>();
        for (int num : nums) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }

        for (int count : freqMap.values()) {
            if (count > 1)
                return true;
        }
        return false;
    }
}