package base.offer2;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q18
 *
 * @author evan
 * @date 2021/9/23
 */
public class Q18 {
    public static boolean isPalindrome(String s) {
        int len = s.length();
        if (len <= 1) {
            return true;
        }
        int l = 0, r = len - 1;
        while (l < r) {
            while (l < len && !Character.isLetterOrDigit(s.charAt(l))) {
                ++l;
            }

            while (r >= 0 && !Character.isLetterOrDigit(s.charAt(r))) {
                --r;
            }
            if (l > r) {
                return true;
            }
            if (Character.toLowerCase(s.charAt(l)) != Character.toLowerCase(s.charAt(r))) {
                return false;
            }
            ++l;
            --r;
        }

        return true;
    }

    public static void main(String[] args) {
        System.out.println(isPalindrome("abb"));
    }
}
