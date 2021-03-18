package base;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: Q242
 *
 * @author evan
 * @date 2021/3/19
 */
public class Q242 {
    public boolean isAnagram(String s, String t) {
        int len = s.length();
        if (len != t.length()) {
            return false;
        }
        char[] sArray = s.toCharArray();
        char[] tArray = t.toCharArray();
        Arrays.sort(sArray);
        Arrays.sort(tArray);
        return Arrays.equals(sArray, tArray);
    }

    public static void main(String[] args) {
        Q242 q = new Q242();
        System.out.println(q.isAnagram("rat", "car"));
    }
}
