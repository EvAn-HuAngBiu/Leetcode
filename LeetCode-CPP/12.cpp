#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    map<int ,string> m = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"},
                          {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
    int order[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    int binarySearch(int target) {
        int beg = 0, end = 12, mid;
        while (beg <= end) {
            mid = (beg + end) / 2;
            if (target == order[mid]) {
                return mid;
            } else if (target > order[mid]) {
                beg = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return end;
    }

    string intToRoman(int num) {
        string result;
        int index;
        while (num) {
            index = binarySearch(num);
            result += m[order[index]];
            num -= order[index];
        }
        return result;
    }
};

int main()
{
    cout << Solution().intToRoman(1994) << endl;
    return 0;
}