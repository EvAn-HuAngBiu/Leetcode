package niuke.meituan;
import java.util.*;

/**
 * <p>
 * Project: LeetCode-Java
 * File: S2021G0801
 *
 * @author evan
 * @date 2021/8/25
 */
public class S2021G0801 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt(), q = in.nextInt();
        // 判断某行是否加锁
        boolean[] locks = new boolean[m + 1];
        // 保存这本书在哪一行
        int[] books = new int[n + 1];
        for (int i = 0; i < q; ++i) {
            int op = in.nextInt(), x, y;
            if (op == 1) {
                x = in.nextInt();
                y = in.nextInt();
                // books[x]<0说明书在小团手上，books[x]>0且该行加锁说明原来放书的行加锁，locks[y]为true表示新行加锁
                if (books[x] < 0 || (books[x] > 0 && locks[books[x]]) || locks[y]) {
                    continue;
                }
                books[x] = y;
            } else if (op == 2) {
                y = in.nextInt();
                locks[y] = true;
            } else if (op == 3) {
                y = in.nextInt();
                locks[y] = false;
            } else if (op == 4) {
                x = in.nextInt();
                y = books[x];
                // y<0: 当前书已经被借走，y=0：当前书不存在，否则如果行加锁则取书失败
                if (y <= 0 || locks[y]) {
                    System.out.println(-1);
                } else {
                    System.out.println(y);
                    books[x] = -y;
                }
            } else if (op == 5) {
                x = in.nextInt();
                y = books[x];
                // 还书操作，只有借走书，即y<0才允许还书
                // 这里还书不是还回书架
                if (y < 0) {
                    books[x] = 0;
                }
            }
        }
    }
}
