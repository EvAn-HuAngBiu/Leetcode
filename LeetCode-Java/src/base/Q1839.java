package base;

/**
 * Project: LeetCode-Java
 * File: Q1839
 *
 * @author evan
 * @date 2021/4/28
 */
public class Q1839 {
    private int getChar(char c) {
        switch (c) {
            case 'a': return 0;
            case 'e': return 1;
            case 'i': return 2;
            case 'o': return 3;
            case 'u': return 4;
            default: return -1;
        }
    }

    public int longestBeautifulSubstring(String word) {
        int len = word.length();
        if (len < 5) {
            return 0;
        }
        int[] dp = new int[len];
        dp[0] = word.charAt(0) == 'a' ? 1 : 0;
        for (int i = 1; i < len; ++i) {
            char cur = word.charAt(i), pre = word.charAt(i - 1);
            int cIndex = getChar(cur), pIndex = getChar(pre);
            if (cIndex >= pIndex && cIndex - pIndex <= 1) {
                dp[i] = dp[i - 1] + 1;
            } else if (cur == 'a') {
                dp[i] = 1;
            } else {
                dp[i] = 0;
            }
        }
        int maxLen = 0;
        for (int i = 0; i < len; ++i) {
            if (word.charAt(i) == 'u' && i - dp[i] + 1 < len && word.charAt(i - dp[i] + 1) == 'a' && dp[i] > maxLen) {
                maxLen = dp[i];
            }
        }
        return maxLen;
    }

    public static void main(String[] args) {
        Q1839 q = new Q1839();
        System.out.println(q.longestBeautifulSubstring("aeiaaioaaaaeiiiiouuuooaauuaeiu"));
    }
}
