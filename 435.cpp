#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

struct Space {
    int beg;
    int end;
    Space() {}
    Space(int beg, int end) : beg(beg), end(end) {}
};

bool cmp(const Space& s1, const Space& s2) {
    return s1.end < s2.end;
}

bool cross(const Space& s1, const Space& s2) {
    return s1.end <= s2.beg || s2.end <= s1.beg;
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    vector<Space> vs;
    for (const vector<int>& v : intervals) {
        vs.push_back(Space(v[0], v[1]));
    }
    sort(vs.begin(), vs.end(), cmp);
    stack<Space> st;
    for (const Space& sp : vs) {
        if (!st.empty() && !cross(sp, st.top())) {
            continue;
        }
        st.push(sp);
    }
    return intervals.size() - st.size();
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        vector<int> cur(2);
        cin >> cur[0] >> cur[1];
        v[i] = cur;
    }
    cout << eraseOverlapIntervals(v) << endl;
    return 0;
}