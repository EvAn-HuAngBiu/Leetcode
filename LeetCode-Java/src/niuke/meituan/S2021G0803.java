package niuke.meituan;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

/**
 * <p>
 * Project: LeetCode-Java
 * File: S2021G0803
 *
 * @author evan
 * @date 2021/8/25
 */
public class S2021G0803 {
    static class Node {
        int group1, price;

        public Node(int group1, int price) {
            this.group1 = group1;
            this.price = price;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] counts = new int[4];
        for (int i = 0; i < 4; ++i) {
            counts[i] = in.nextInt();
        }

        List<Node> list = new ArrayList<>(3);
        list.add(new Node(0, in.nextInt()));
        list.add(new Node(1, in.nextInt()));
        list.add(new Node(2, in.nextInt()));

        list.sort(Comparator.comparingInt(o -> -o.price));

        long total = 0;
        for (int i = 0; i < 3; ++i) {
            Node node = list.get(i);
            int g1 = node.group1;
            if (counts[g1] <= 0) {
                continue;
            } else if (counts[3] == 0) {
                break;
            }
            int count = Math.min(counts[g1], counts[3]);
            total += (long) count * node.price;
            counts[g1] -= count;
            counts[3] -= count;
        }
        System.out.println(total);
    }
}
