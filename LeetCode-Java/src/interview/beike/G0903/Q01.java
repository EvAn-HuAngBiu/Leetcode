package interview.beike.G0903;

import java.util.Scanner;

public class Q01 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; ++i) {
            int n = in.nextInt();
            if (n == 1) {
                System.out.println(1);
                continue;
            }
            if (n % 2 == 0) {
                System.out.println(n / 2);
            } else {
                System.out.println(n / 2 + 1);
            }
        }
    }
}
