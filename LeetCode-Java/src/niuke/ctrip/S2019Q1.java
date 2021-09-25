package niuke.ctrip;

import java.util.*;

/**
 * Project: LeetCode-Java
 * File: S2019Q1
 *
 * @author evan
 * @date 2021/4/15
 */
public class S2019Q1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int record = in.nextInt();
        int target = in.nextInt();
        // Record[] records = new Record[record];
        Set<Integer> set = new TreeSet<>();
        int id, start, end;
        for (int i = 0; i < record; i++) {
            id = in.nextInt();
            start= in.nextInt();
            end = in.nextInt();
            if (start <= target && target <= end) {
                set.add(id);
            }
        }
        if (set.isEmpty()) {
            System.out.println("null");
        } else {
            set.forEach(System.out::println);
        }
    }
}
