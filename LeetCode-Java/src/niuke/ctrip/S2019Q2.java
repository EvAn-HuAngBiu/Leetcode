package niuke.ctrip;

import java.util.LinkedHashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * Project: LeetCode-Java
 * File: S2019Q2
 *
 * @author evan
 * @date 2021/4/15
 */
public class S2019Q2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cap = in.nextInt();
        in.nextLine();
        LinkedHashMap<Integer, Integer> map = new LinkedHashMap<>(cap);

        while (in.hasNextLine()) {
            String line = in.nextLine();
            String[] command = line.split(" ");
            if (command[0].equals("p")) {
                int key = Integer.parseInt(command[1]), value = Integer.parseInt(command[2]);
                if (cap == 0) {
                    continue;
                }
                if (!map.containsKey(key) && map.size() >= cap) {
                    int firstKey = map.keySet().iterator().next();
                    map.remove(firstKey);
                }
                map.put(key, value);
            } else {
                int key = Integer.parseInt(command[1]);
                if (!map.containsKey(key)) {
                    System.out.println(-1);
                } else {
                    int val = map.get(key);
                    System.out.println(val);
                    map.remove(key);
                    map.put(key, val);
                }
            }
        }
    }
}
