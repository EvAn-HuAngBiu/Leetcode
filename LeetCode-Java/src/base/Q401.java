package base;

import java.util.*;

/**
 * Project: LeetCode-Java
 * File: Q401
 *
 * @author evan
 * @date 2021/7/28
 */
public class Q401 {
    public static final int MAX_HOUR = 12;
    public static final int MAX_MINUTE = 60;
    public static final int[] HOURS = {1, 2, 4, 8};
    public static final int[] MINUTES = {1, 2, 4, 8, 16, 32};
    private static final Set<String> result = new TreeSet<>();

    private static void dfs(int remain, int hr, int min) {
        if (remain == 0) {
            result.add(String.format("%d:%02d", hr, min));
            return;
        }
        for (int i = 0; i < HOURS.length; ++i) {
            int nh;
            if ((nh = HOURS[i]) >= 0 && nh + hr < MAX_HOUR) {
                HOURS[i] = -1;
                dfs(remain - 1, nh + hr, min);
                HOURS[i] = nh;
            }
        }
        for (int i = 0; i < MINUTES.length; ++i) {
            int nm;
            if ((nm = MINUTES[i]) >= 0 && nm + min < MAX_MINUTE) {
                MINUTES[i] = -1;
                dfs(remain - 1, hr, nm + min);
                MINUTES[i] = nm;
            }
        }
    }

    public static List<String> readBinaryWatch(int turnedOn) {
        dfs(turnedOn, 0, 0);
        return new ArrayList<>(result);
    }

    public static void main(String[] args) {
        System.out.println(readBinaryWatch(2));
    }
}
