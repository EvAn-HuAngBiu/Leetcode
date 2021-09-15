package base.offer2;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q04
 *
 * @author evan
 * @date 2021/9/15
 */
public class Q04 {
    public static int singleNumber(int[] nums) {
        int result = 0, cnt;
        for (int i = 0; i < 32; ++i) {
            cnt = 0;
            for (int num : nums) {
                if ((num >> i & 1) == 1) {
                    ++cnt;
                }
            }
            if (cnt % 3 != 0) {
                result |= (1 << i);
            }
        }

        return result;
    }

    public static void main(String[] args) {
        System.out.println(singleNumber(new int[] {2, 2, 2, 9, 1, 1, 1}));
    }
}
