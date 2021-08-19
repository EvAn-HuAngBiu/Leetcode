package base;

/**
 * @author evan
 * @project LeetCode-Java
 * @file Q331
 * @date 2021/8/19
 */
public class Q331 {
    public static String[] split;
    public static int[] indexes;

    /*
    * 这种解法的思路是，定义一个indexes数组来保存当前结点直接的左、右结点是否被使用，0表示未被使用，1表示左结点被使用，2表示右结点被使用
    * 遍历前序序列的每一个结点值，默认连接在左结点上即indexes[pre]=1时，则连接在右结点上（即令indexes[pre]=2），对于空节点，由于不能
    * 再次连接，默认设置左右结点均满的状态即indexes[cur]=2。
    * 每次判断时，如果indexes[pre]=1，说明可以挂在前一个结点的左结点上，合法，继续下一个遍历
    * 如果indexes[pre]=2，说明前一个结点的左右结点都满，那要继续向前寻找一个可以放置的结点，即indexes[pre]=1的结点，如果找不到则失败
    * 最后循环结束后，遍历整个indexes数组，必须保证每个结点左右结点都满才是合法的，即indexes数组所有值均为2（空结点已经被设置为2）
    * */
    public static boolean isValidSerialization(String preorder) {
        split = preorder.split(",");
        int len = split.length;
        if (len == 0 || (len == 1 && split[0].equals("#"))) {
            return true;
        }
        indexes = new int[len];
        indexes[0] = split[0].equals("#") ? 2 : 1;

        for (int i = 1; i < len; ++i) {
            if (!split[i].equals("#")) {
                indexes[i] = 1;
            } else {
                indexes[i] = 2;
            }
            int pre = i - 1;
            if (indexes[pre] == 1) {
                continue;
            }
            while (pre >= 0 && indexes[pre] != 1) {
                --pre;
            }
            if (pre < 0) {
                return false;
            }
            indexes[pre] = 2;
        }
        for (int i : indexes) {
            if (i != 2) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(isValidSerialization("#,#,#"));
    }
}
