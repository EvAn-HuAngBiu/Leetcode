package base;

/**
 * Project: LeetCode-Java
 * File: Q383
 *
 * @author evan
 * @date 2021/5/20
 */
public class Q383 {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] count = new int[26];
        int rLen = ransomNote.length(), mLen = magazine.length();
        if (mLen < rLen) {
            return false;
        }
        for (int i = 0; i < mLen; ++i) {
            ++count[magazine.charAt(i) - 'a'];
        }
        for (int i = 0; i < rLen; ++i) {
            char cur = ransomNote.charAt(i);
            if (--count[cur - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
}
