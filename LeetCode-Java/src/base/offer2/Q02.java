package base.offer2;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q02
 *
 * @author evan
 * @date 2021/9/14
 */
public class Q02 {
    public static String addBinary(String a, String b) {
        int l1 = a.length() - 1, l2 = b.length() - 1;
        StringBuilder result = new StringBuilder();
        int add = 0;
        int v1, v2, t;
        while (l1 >= 0 && l2 >= 0) {
            v1 = a.charAt(l1--) - '0';
            v2 = b.charAt(l2--) - '0';
            t = v1 ^ v2 ^ add;
            add = (v1 & v2) | (v1 & add) | (v2 & add);
            result.append(t);
        }

        String temp = (l1 < 0 ? b : a);
        int last = (l1 < 0 ? l2 : l1);
        while (last >= 0) {
            v1 = temp.charAt(last--) - '0';
            t = v1 ^ add;
            add = (v1 & add);
            result.append(t);
        }
        if (add == 1) {
            result.append(1);
        }

        return result.reverse().toString();
    }

    public static void main(String[] args) {
        System.out.println(addBinary("11", "10"));
    }
}
