#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int binaryFind(const vector<int>& nums, int target, int beg, int end) {
    int mid;
    while (beg <= end) {
        mid = (beg + end) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target < nums[mid]) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }
    return -1;
}

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result(2);
    int size = numbers.size(), find;
    for (int i = 0; i < size; i++) {
        find = binaryFind(numbers, target - numbers[i], i + 1, size - 1);
        if (find != -1) {
            result[0] = i + 1;
            result[1] = find + 1;
            break;
        }
    }
    return result;
}

vector<int> twoSum2(vector<int>& numbers, int target) {
    int p = 0, q = numbers.size() - 1, sum;
    while (p < q) {
        sum = numbers[p] + numbers[q];
        if (sum == target) {
            break;
        } else if (sum < target) {
            ++p;
        } else {
            --q;
        }
    }
    vector<int> v;
    v.push_back(p + 1);
    v.push_back(q + 1);
    return v;
}

int main()
{
    vector<int> v = {5, 25, 75};
    for (int i : twoSum2(v, 100)) {
        cout << i << endl;
    }
    return 0;
}