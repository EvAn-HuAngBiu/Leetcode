#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

bool cmp(const vector<int>& v1, const vector<int>& v2) {
    if (v1[1] == v2[1]) {
        return v1[0] > v2[0];
    }
    return v1[1] < v2[1];
}

int intersectionSizeTwo(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    int cnt = 2, beg = intervals[0][1] - 1, end = intervals[0][1], size = intervals.size();
    for (int i = 1; i < size; ++i) {
        if (intervals[i][0] <= beg) {
            continue;
        }
        if (intervals[i][0] > end) {
            cnt += 2;
            beg = intervals[i][1] - 1;
            end = intervals[i][1];
        } else {
            ++cnt;
            beg = end;
            end = intervals[i][1];
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> v = {
            {2,10},{3,7},{3,15},{4,11},{6,12},{6,16},{7,8},{7,11},{7,15},{11,12}
    };
    cout << intersectionSizeTwo(v) << endl;
    return 0;
}