package base.offer;

public class J10 {
    public int fib(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        }
        int pre1 = 1, pre2 = 0, temp;
        for (int i = 2; i <= n; ++i) {
            temp = (int)((pre1 % (1e9+7) + pre2 % (1e9+7)) % (1e9+7));
            pre2 = pre1;
            pre1 = temp;
        }
        return pre1;
    }

    public static void main(String[] args) {
        J10 j = new J10();
        System.out.println(j.fib(100));
    }
}
