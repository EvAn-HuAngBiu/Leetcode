package base;

/**
 * Project: LeetCode-Java
 * File: Q258
 *
 * @author evan
 * @date 2021/3/19
 */
public class Q258 {
    public int addDigits(int num) {
        if (num < 10) {
            return num;
        }
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return addDigits(sum);
    }

    public static void main(String[] args) {
        Q258 q = new Q258();
        System.out.println(q.addDigits(5));
    }
}
