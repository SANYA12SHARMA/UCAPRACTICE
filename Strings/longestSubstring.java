
import java.util.HashMap;

class longestSubString {
    public static int lengthOfLongestSubstring(String s) {
        int maxLen = 0;
        int n = s.length();
        if (n == 0 || n == 1) {
            return n;
        }
        HashMap<Character, Integer> map = new HashMap<>();
        int l = 0;
        int r = 0;
        while (r < s.length()) {
            if (map.containsKey(s.charAt(r))) {
                l = Math.max(l, map.get(s.charAt(r)) + 1);
            }
            map.put(s.charAt(r), r);
            maxLen = Math.max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }

    public static void main(String[] args) {
        assert lengthOfLongestSubstring("pwwkew") == 3;
    }
}