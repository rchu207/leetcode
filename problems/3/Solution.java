package tw.idv.rchu.leetcode;

import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int longestLength = 0;
        Map<Character, Integer> map = new HashMap<>();
        int i = 0;

        for (int j = 0; j < s.length(); j++) {
            if (map.containsKey(s.charAt(j))) {
                if (j - i > longestLength) {
                    longestLength = j - i;
                }
                if (map.get(s.charAt(j)) + 1 > i) {
                    i = map.get(s.charAt(j)) + 1;
                }
            }
            map.put(s.charAt(j), j);
        }

        if (s.length() - i > longestLength) {
            longestLength = s.length()  - i;
        }
        return longestLength;
    }
}
