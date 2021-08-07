package base;

import java.util.ArrayList;
import java.util.List;

/**
 * Project: LeetCode-Java
 * File: Q412
 *
 * @author evan
 * @date 2021/8/7
 */
public class Q412 {
    public static List<String> fizzBuzz(int n) {
        List<String> list = new ArrayList<>(n);
        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) {
                list.add("FizzBuzz");
            } else if (i % 3 == 0) {
                list.add("Fizz");
            } else if (i % 5 == 0) {
                list.add("Buzz");
            } else {
                list.add(String.valueOf(i));
            }
        }
        return list;
    }

    public static void main(String[] args) {
        System.out.println(fizzBuzz(15));
    }
}
