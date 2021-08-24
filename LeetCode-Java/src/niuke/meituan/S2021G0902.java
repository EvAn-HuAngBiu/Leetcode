package niuke.meituan;

import java.util.*;

/**
 * <p>
 * Project: LeetCode-Java
 * File: S2021G0902
 *
 * @author evan
 * @date 2021/8/24
 */
public class S2021G0902 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), x = in.nextInt();
        List<Integer> list = new ArrayList<>(n);
        for (int i = 0; i < n; ++i) {
            list.add(in.nextInt());
        }
        list.sort(Comparator.reverseOrder());
        int count = 0, min = list.get(x - 1);
        for (int i = 0; i < n; ++i) {
            int cur = list.get(i);
            if (cur == 0 || cur < min) {
                break;
            }
            ++count;
        }
        System.out.println(count);
    }
}
