package interview.vip;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q02
 *
 * @author evan
 * @date 2021/9/15
 */
public class Q02 {
    public static int maxSum(String[] words) {
        int len = words.length;
        int[] array = new int[len];
        int maxLen = -1;

        for (int i = 0; i < len; ++i) {
            char[] cur = words[i].toCharArray();
            int temp = 0;
            for (char c : cur) {
                temp |= (1 << (c - 'a'));
            }
            array[i] = temp;
        }

        int cnt0 = 0, cnt1 = 0, p, q;
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if ((array[i] & array[j]) == 0) {
                    cnt0 = 0;
                    cnt1 = 0;
                    p = array[i];
                    q = array[j];
                    for (int k = 0; k < 32; ++k) {
                        if (((p >>> k) & 1) == 1) {
                            ++cnt0;
                        }
                        if (((q >>> k) & 1) == 1) {
                            ++cnt1;
                        }
                    }

                    maxLen = Math.max(maxLen, cnt0 + cnt1);
                }
            }
        }

        return maxLen;
    }

    public static void main(String[] args) {
        String[] array = {"a","aba","abc","d","cd","bcd","abcd"};
        System.out.println(maxSum(array));
    }
}
