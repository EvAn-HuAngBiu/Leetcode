package base.offer2;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q05
 *
 * @author evan
 * @date 2021/9/15
 */
public class Q05 {
    public static int maxProduct(String[] words) {
        int len = words.length;
        int[] array = new int[len];
        int maxLen = 0;

        for (int i = 0; i < len; ++i) {
            char[] cur = words[i].toCharArray();
            int temp = 0;
            for (char c : cur) {
                temp |= (1 << (c - 'a'));
            }
            array[i] = temp;
        }

        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if ((array[i] & array[j]) == 0) {
                    maxLen = Math.max(maxLen, words[i].length() * words[j].length());
                }
            }
        }

        return maxLen;
    }

    public static void main(String[] args) {
        String[] arrays = {"a","aa","aaa","aaaa"};
        System.out.println(maxProduct(arrays));
    }
}
