class Solution {
    public String[] divideString(String s, int k, char fill) {
        int size = s.length();
        int numOfGroups = (size + k - 1) / k;
        String dividedStrings[] = new String[numOfGroups];

        for(int i = 0; i < numOfGroups; i++) {
            int startIndex = i*k;
            int endIndex = Math.min(startIndex+k, size);
            StringBuilder sb = new StringBuilder();
            sb.append(s.substring(startIndex, endIndex));
            while(sb.length() < k) sb.append(fill);
            dividedStrings[i] = sb.toString();
        }

        return dividedStrings;
    }
}
