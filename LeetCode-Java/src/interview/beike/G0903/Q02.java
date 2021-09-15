package interview.beike.G0903;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Q02 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; ++i) {
            int len = Integer.parseInt(br.readLine());
            char[] cur = br.readLine().toCharArray();
            LinkedList<Character> stack = new LinkedList<>();
            for (char c : cur) {
                if (c == '(') {
                    stack.push(c);
                } else if (stack.isEmpty() || stack.getFirst() != '(') {
                    stack.push(c);
                } else {
                    stack.pop();
                }
            }
            System.out.println(stack.size() / 2);
        }
    }
}
