package interview.beike.G0903;

import java.util.*;

public class Q03 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), k = in.nextInt(), m = in.nextInt();
        int[] w = new int[100010];
        long[] ans = new long[100010];
        List<Long> sum = new ArrayList<>();

        for (int i = 1; i <= n; ++i) {
            w[i] = in.nextInt();
        }
        Arrays.sort(w, 1, n + 1);

    }
}


