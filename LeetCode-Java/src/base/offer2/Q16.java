package base.offer2;

import java.util.BitSet;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q16
 *
 * @author evan
 * @date 2021/9/23
 */
public class Q16 {
    public static int lengthOfLongestSubstring(String s) {
        int len = s.length();
        if (len == 0) {
            return 0;
        }
        BitSet[] dp = new BitSet[len];
        Map<Integer, Integer> last = new HashMap<>();


        int maxLen = 1;
        for (int i = 0; i < len; ++i) {
            dp[i] = new BitSet();
            int offset = s.charAt(i);
            if (i == 0 || dp[i - 1].get(offset)) {
                int pre = last.getOrDefault(offset, i - 1);
                if (i == 0 || pre == i - 1) {
                    dp[i].set(offset);
                } else {
                    dp[i].or(dp[i - 1]);
                    dp[i].xor(dp[pre]);
                    dp[i].set(offset);
                }
            } else {
                dp[i].or(dp[i - 1]);
                dp[i].set(offset);
                maxLen = Math.max(maxLen, dp[i].cardinality());
            }
            last.put(offset, i);

            // int offset = s.charAt(i) - 'a';
            // if (i == 0 || (dp[i - 1] >>> offset & 1) == 1) {
            //     int pre = last[offset];
            //     if (i == 0 || pre == i - 1) {
            //         dp[i] = (1 << offset);
            //     } else {
            //         dp[i] = dp[pre] ^ dp[i - 1] | (1 << offset);
            //     }
            // } else {
            //     dp[i] = dp[i - 1] | (1 << offset);
            //     int temp = dp[i], cnt = 0;
            //     while (temp != 0) {
            //         if ((temp & 1) == 1) {
            //             ++cnt;
            //         }
            //         temp >>>= 1;
            //     }
            //     maxLen = Math.max(maxLen, cnt);
            // }
            // last[offset] = i;
        }

        return maxLen;
    }

    public static int lengthOfLongestSubstring2(String s) {
        int len = s.length();
        if (len == 0) {
            return 0;
        }
        HashMap<Character, Integer> map = new HashMap<>();
        int l = 0, r = 1, maxLen = 1;
        map.put(s.charAt(0), 0);
        while (r < len) {
            char cur = s.charAt(r);
            if (map.containsKey(cur)) {
                int last = map.get(cur);
                while (l <= last) {
                    map.remove(s.charAt(l++));
                }
            } else {
                map.put(cur, r);
                ++r;
                maxLen = Math.max(maxLen, map.size());
            }
        }

        return maxLen;
    }

    public static void main(String[] args) {
        System.out.println(lengthOfLongestSubstring2("bpfbhmipx"));
        // System.out.println(lengthOfLongestSubstring2("pwwkew"));
    }
}
