package base;

import java.util.LinkedList;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q227
 *
 * @author evan
 * @date 2021/10/9
 */
public class Q227 {
    private int calc(int a, int b, char c) {
        switch (c) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            default: return a / b;
        }
    }

    private final int[][] tbl = {
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {0, 0, 1, 1},
            {0, 0, 1, 1}
    };

    private boolean cmp(char a, char b) {
        int ia = 0, ib = 0;
        switch (a) {
            case '+': ia = 0; break;
            case '-': ia = 1; break;
            case '*': ia = 2; break;
            default: ia = 3; break;
        }
        switch (b) {
            case '+': ib = 0; break;
            case '-': ib = 1; break;
            case '*': ib = 2; break;
            default: ib = 3; break;
        }
        return tbl[ia][ib] == 1;
    }

    public int calculate(String s) {
        s = s.trim();
        char[] str = s.toCharArray();
        LinkedList<Integer> numbers = new LinkedList<>();
        LinkedList<Character> signs = new LinkedList<>();
        int temp = 0;
        for (char c : str) {
            if (Character.isDigit(c)) {
                temp = temp * 10 + (c - '0');
            } else if (c != ' ') {
                numbers.push(temp);
                temp = 0;
                if (!signs.isEmpty() && cmp(c, signs.peek())) {
                    char pre = signs.pop();
                    do {
                        int n1 = numbers.pop(), n2 = numbers.pop();
                        numbers.push(calc(n2, n1, pre));
                        if (!signs.isEmpty() && cmp(c, signs.peek())) {
                            pre = signs.pop();
                        } else {
                            break;
                        }
                    } while (true);
                }
                signs.push(c);
            }
        }
        numbers.push(temp);

        while (!signs.isEmpty()) {
            int n1 = numbers.pop(), n2 = numbers.pop();
            numbers.push(calc(n2, n1, signs.pop()));
        }
        return numbers.pop();
    }

    public static void main(String[] args) {
        System.out.println(new Q227()
                .calculate("1*2-3/4+5*6-7*8+9/10"));
    }
}
