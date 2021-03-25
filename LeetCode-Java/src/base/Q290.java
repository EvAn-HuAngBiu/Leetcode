package base;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * Project: LeetCode-Java
 * File: Q290
 *
 * @author evan
 * @date 2021/3/23
 */
public class Q290 {
    public boolean wordPattern(String pattern, String s) {
        Map<String, Character> s2c = new HashMap<>();
        Map<Character, String> c2s = new HashMap<>();
        String[] strs = s.split(" ");
        int len = strs.length;
        if (pattern.length() != len) {
            return false;
        }
        for (int i = 0; i < len; i++) {
            char cur = pattern.charAt(i);
            if ((s2c.containsKey(strs[i]) && s2c.get(strs[i]) != cur)
                || (c2s.containsKey(cur) && !c2s.get(cur).equals(strs[i]))) {
                return false;
            }
            s2c.put(strs[i], cur);
            c2s.put(cur, strs[i]);
        }
        return true;
    }

    public static void main(String[] args) {
        String pat = "abcd";
        String s = "mul muli mulit tql";
        Q290 q = new Q290();
        System.out.println(q.wordPattern(pat, s));
    }
}
