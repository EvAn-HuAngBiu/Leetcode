package base;

/**
 * Project: LeetCode-Java
 * File: Q1603
 *
 * @author evan
 * @date 2021/3/19
 */
class ParkingSystem {
    private Integer big;
    private Integer medium;
    private Integer small;

    public ParkingSystem(int big, int medium, int small) {
        this.big = big;
        this.medium = medium;
        this.small = small;
    }

    public boolean addCar(int carType) {
        if (carType == 1 && big > 0) {
            big -= 1;
            return true;
        } else if (carType == 2 && medium > 0) {
            medium -= 1;
            return true;
        } else if (carType == 3 && small > 0) {
            small -= 1;
            return true;
        }
        return false;
    }
}

public class Q1603 {
}
