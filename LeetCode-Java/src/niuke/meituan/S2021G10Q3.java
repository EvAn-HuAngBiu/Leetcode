package niuke.meituan;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

/**
 * Project: LeetCode-Java
 * File: S2021G10Q3
 *
 * @author evan
 * @date 2021/5/7
 */
public class S2021G10Q3 {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        int cnt = Integer.parseInt(reader.readLine());
        Queue<Integer> empty = new PriorityQueue<>(), one = new PriorityQueue<>();
        for (int k = 0; k < cnt; ++k) {
            empty.clear();
            one.clear();
            int N = Integer.parseInt(reader.readLine());
            String value = reader.readLine();
            for (int i = 1; i <= N; ++i) {
                char c = value.charAt(i - 1);
                if (c == '0') {
                    empty.add(i);
                } else if (c == '1') {
                    one.add(i);
                }
            }
            int count = Integer.parseInt(reader.readLine());
            String next = reader.readLine();
            for (int i = 0; i < count; ++i) {
                char c = next.charAt(i);
                if (c == 'M') {
                    if (!one.isEmpty()) {
                        writer.write(Integer.toString(one.poll()));
                        writer.newLine();
                    } else {
                        int top = empty.poll();
                        one.add(top);
                        writer.write(Integer.toString(top));
                        writer.newLine();
                    }
                } else {
                    if (!empty.isEmpty()) {
                        int top = empty.poll();
                        one.add(top);
                        writer.write(Integer.toString(top));
                        writer.newLine();
                    } else {
                        writer.write(Integer.toString(one.poll()));
                        writer.newLine();
                    }
                }
            }
            writer.flush();
        }
    }
}
