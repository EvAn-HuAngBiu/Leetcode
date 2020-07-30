#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(const vector<int> &v, int target) {
        int beg = 0, end = v.size() - 1, mid;
        while (beg <= end) {
            mid = (beg + end) / 2;
            if (v[mid] == target) {
                return mid;
            } else if (v[mid] > target) {
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }
        return end;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        vector<int> head;
        for (const auto &m : matrix) {
            if (m.size()) {
                head.emplace_back(m[0]);
            }
        }
        int b = binarySearch(head, target);
        if (b < 0) {
            return false;
        }
        const vector<int> &m = matrix[b];
        return target == m[binarySearch(m, target)];
    }
};

int main() {
    vector<vector<int> > matrix;
    int target;
    int m, n, e;
    cin >> m;
    cin >> n;
    for (int i = 0; i < m; i++) {
        vector<int> aRow;
        for (int j = 0; j < n; j++) {
            cin >> e;
            aRow.push_back(e);
        }
        matrix.push_back(aRow);
    }
    cin >> target;
    bool res = Solution().searchMatrix(matrix, target);
    cout << (res ? "true" : "false") << endl;
    return 0;
}