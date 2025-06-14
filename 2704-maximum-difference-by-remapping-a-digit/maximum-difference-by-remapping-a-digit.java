class Solution {
        public int minMaxDifference(int num) {
        String numStr = String.valueOf(num);

        char replaceForMax = '`';
        for (char c : numStr.toCharArray()) {
            if (c != '9') {
                replaceForMax = c;
                break;
            }
        }

        String maxNumStr = numStr.replace(replaceForMax, '9');

        char replaceForMin = '`';
        for (char c : numStr.toCharArray()) {
            if (c != '0') {
                replaceForMin = c;
                break;
            }
        }

        String minNumStr = numStr.replace(replaceForMin, '0');
        int res = Integer.parseInt(maxNumStr) - Integer.parseInt(minNumStr);
        return res;
    }
}