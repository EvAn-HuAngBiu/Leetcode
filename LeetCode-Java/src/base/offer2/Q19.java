package base.offer2;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q19
 *
 * @author evan
 * @date 2021/9/25
 */
public class Q19 {
    private static boolean judge(char[] array, int beg, int end, boolean flag) {
        int p = beg, q = end;
        while (p < q) {
            if (array[p] == array[q]) {
                ++p;
                --q;
            } else if (!flag){
                return judge(array, p + 1, q, true) || judge(array, p, q - 1, true);
            } else {
                return false;
            }
        }
        return true;
    }

    public static boolean validPalindrome(String s) {
        if (s.length() <= 1) {
            return true;
        }
        return judge(s.toCharArray(), 0, s.length() - 1, false);
    }

    public static void main(String[] args) {
        System.out.println(validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"));
    }
}
