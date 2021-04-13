package base.offer;

public class J14 {
    public int cuttingRope(int n) {
        int[] dp = new int[n + 1];
        dp[0] = dp[1] = dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = Math.max(dp[i], Math.max(dp[i - j] * j, j * (i - j)));
            }
        }
        return dp[n];
    }

    public static void main(String[] args) {
        J14 j = new J14();
        System.out.println(j.cuttingRope(10));
    }
}
