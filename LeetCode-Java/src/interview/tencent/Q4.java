package interview.tencent;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q4
 *
 * @author evan
 * @date 2021/9/5
 */
public class Q4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), l = in.nextInt(), r = in.nextInt();
        LinkedList<Integer> st1 = new LinkedList<>();
        st1.offer(n);

        boolean flag;
        do {
            flag = false;
            int len = st1.size();
            for (int i = 0; i < len; ++i) {
                int cur = st1.poll();
                if (cur != 0 && cur != 1) {
                    flag = true;
                    st1.offer(cur >> 1);
                    st1.offer(cur % 2);
                    st1.offer(cur >> 1);
                } else {
                    st1.offer(cur);
                }
            }
        } while (flag);

        for (int i = 1; i < l; ++i) {
            st1.poll();
        }
        int cnt = 0;
        for (int i = 0; i <= r - l; ++i) {
            cnt += st1.poll();
        }
        System.out.println(cnt);
    }
}
