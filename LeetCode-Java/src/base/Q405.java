package base;

/**
 * Project: LeetCode-Java
 * File: Q405
 *
 * @author evan
 * @date 2021/6/23
 */
public class Q405 {
    public static String toHex(int num) {
        if (num == 0) {
            return "0";
        }
        int[] bits = new int[32];
        boolean isNeg = num < 0;
        long largeNum = Math.abs((long)num);
        int bit = 31;
        while (largeNum != 0) {
            bits[bit--] = (int) (largeNum % 2);
            largeNum /= 2;
        }
        if (isNeg) {
            int p = 31;
            while (p >= 0) {
                if (bits[p--] == 1) {
                    break;
                }
            }
            for (int i = 0; i <= p; ++i) {
                bits[i] = bits[i] ^ 1;
            }
        }
        StringBuilder result = new StringBuilder();
        boolean hasPre = false;
        int offset = 0;
        for (int i = 0; i < 8; ++i) {
            int cur = bits[offset] * 8 + bits[offset + 1] * 4 + bits[offset + 2] * 2 + bits[offset + 3];
            if (hasPre || cur != 0) {
                result.append(cur < 10 ? cur : String.valueOf((char)(cur + 'a' - 10)));
                hasPre = true;
            }
            offset += 4;
        }
        return result.toString();
    }

    public static void main(String[] args) {
        System.out.println(toHex(-2147483648));
    }
}
