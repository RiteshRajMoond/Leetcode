import java.util.Arrays;
import java.util.HashMap;

class Solution {
    public int minimumDeletions(String word, int k){
        HashMap<Character, Integer> freqMap = new HashMap<>();
        for(char c: word.toCharArray()) {
            freqMap.put(c, freqMap.getOrDefault(c, 0)+1);
        }

        int[] freq = new int[freqMap.size()];
        
        int idx = 0;
        for(char c : freqMap.keySet()) {
            freq[idx++] = freqMap.get(c);
        }

        Arrays.sort(freq);

        int minDeletions = Integer.MAX_VALUE, j = 0, sumLeft = 0, windowSum = 0, totalSum = word.length();

        for(int i = 0; i < freq.length; i++) {
            int from = freq[i], to = from+k;

            while(j < freq.length && freq[j] <= to) {
                windowSum += freq[j];
                j++;
            }

            int countRight = freq.length - j;
            int sumRight = totalSum - windowSum;
            int delettionsRight = sumRight - countRight*to;

            int curDeletions = sumLeft + delettionsRight;
            minDeletions = Math.min(curDeletions, minDeletions);

            sumLeft += freq[i];
            windowSum -= freq[i];
            totalSum -= freq[i];
        }

        return minDeletions;
    }
}