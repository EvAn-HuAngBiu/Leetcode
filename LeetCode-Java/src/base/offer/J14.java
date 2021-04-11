package base.offer;

public class J14 {
    private int[] dp;

    public int cuttingRope(int n) {
        dp = new int[n + 1];
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            for (int j = 2; j < i; ++j) {
                dp[i] = Math.max(dp[i], dp[j] * (i - j));
            }
        }
        return dp[n];
    }

    public static void main(String[] args) {
        J14 j = new J14();
        System.out.println(j.cuttingRope(10));
    }
}
