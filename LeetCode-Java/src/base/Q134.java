package base;

/**
 * Project: LeetCode-Java
 * File: Q134
 *
 * @author evan
 * @date 2021/8/6
 */
public class Q134 {
    public static int canCompleteCircuitEargrly(int[] gas, int[] cost) {
        int len = gas.length;
        if (len == 1) {
            return cost[0] <= gas[0] ? 0 : -1;
        }
        // 改进：利用贪心算法，如果在某个加油站失败说明在这个加油站之前的任意一个加油站都无法到达这里
        // 因为如果能到达某个加油站时，剩余的油量一定大于等于0，也一定大于等于从某个加油站出发时的油量
        // 如果多的都无法到达，那么从这个加油站出发也必定无法到达。
        outer:
        for (int i = 0; i < len;) {
            int remain = 0, cur = i, t = i;
            do {
                remain += gas[cur];
                if (remain >= cost[cur]) {
                    remain -= cost[cur];
                } else {
                    i = t + 1;
                    continue outer;
                }
                cur = (cur + 1) % len;
            } while (i != cur);
            return cur;
        }
        return -1;
    }

    public static int canCompleteCircuit(int[] gas, int[] cost) {
        int len = gas.length;
        if (len == 1) {
            return cost[0] <= gas[0] ? 0 : -1;
        }
        outer:
        for (int i = 0; i < len; ++i) {
            int remain = 0, cur = i;
             do {
                remain += gas[cur];
                if (remain >= cost[cur]) {
                    remain -= cost[cur];
                } else {
                    continue outer;
                }
                cur = (cur + 1) % len;
            } while (i != cur);
            return cur;
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] gas = {1,2,3,4,5}, cost = {3,4,5,1,2};
        System.out.println(canCompleteCircuitEargrly(gas, cost));
    }
}
