package niuke.meituan;

import java.util.Scanner;

/**
 * <p>
 * Project: LeetCode-Java
 * File: S2021G0703
 *
 * @author evan
 * @date 2021/8/26
 */
public class S2021G0703 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int m = in.nextInt(), n = in.nextInt();
        in.nextLine();
        String template = in.nextLine(), find = in.nextLine();
        int findIdx = 0;
        long sum = 0;
        char curFind = find.charAt(findIdx);
        for (int i = 0; i < m; ++i) {
            if (curFind == template.charAt(i)) {
                sum += i + 1;
                if (++findIdx == n) {
                    break;
                }
                curFind = find.charAt(findIdx);
            }
        }
        if (findIdx == n) {
            System.out.println("Yes");
            System.out.println(sum);
        } else {
            System.out.println("No");
        }
    }
}
