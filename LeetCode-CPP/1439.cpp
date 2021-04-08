#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// BFS超时
//int kthSmallest(vector<vector<int>>& mat, int k) {
//    priority_queue<int> pq;
//    deque<pair<int, int> > q;
//    int m = mat.size(), n = mat[0].size();
//    for (int i = 0; i < n; i++) {
//        q.push_back(pair<int, int>(0, mat[0][i]));
//        while (!q.empty()) {
//            pair<int, int> cur = q.front();
//            q.pop_front();
//            if (cur.first == m - 1) {
//                if (pq.size() < k) {
//                    pq.push(cur.second);
//                } else if (pq.top() > cur.second) {
//                    pq.pop();
//                    pq.push(cur.second);
//                }
//                continue;
//            }
//            for (int j = 0; j < n; j++) {
//                int sum = mat[cur.first + 1][j] + cur.second;
//                if (pq.size() < k || sum < pq.top()) {
//                    q.push_back(pair<int, int>(cur.first + 1, sum));
//                }
//            }
//        }
//        q.clear();
//    }
//    return pq.top();
//}

struct Index {
    vector<int> index;
    Index() {}
    Index(const vector<int>& i) {
        index = vector<int>(i);
    }

    bool operator<(const Index& i1) const {
        if (this->index.size() != i1.index.size()) {
            return false;
        }
        for (int i = 0; i < this->index.size(); i++) {
            if (this->index[i] != i1.index[i]) {
                return this->index[i] < i1.index[i];
            }
        }
        return false;
    }
};

struct cmp {
    bool operator()(const pair<int, Index>& i1, const pair<int, Index>& i2) const {
        if (i1.first == i2.first) {
            return i1.second < i2.second;
        }
        return i1.first > i2.first;
    }
};

int kthSmallest(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    Index index(vector<int>(m, 0));
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += mat[i][0];
    }
    priority_queue<pair<int, Index>, vector<pair<int, Index>>, cmp> pq;
    pq.push(pair<int, Index>(sum, index));
    set<Index> s;
    s.insert(index);
    for (int i = 0; i < k; i++) {
        pair<int, Index> cur = pq.top();
        pq.pop();
        vector<int> curIndexVec(cur.second.index);
        sum = cur.first;
        for (int j = 0; j < m; j++) {
            if (curIndexVec[j] < n - 1) {
                Index curIndex(curIndexVec);
                ++curIndex.index[j];
                if (s.find(curIndex) == s.end()) {
                    int newSum = sum + mat[j][curIndex.index[j]] - mat[j][curIndex.index[j] - 1];
                    pq.push(pair<int, Index>(newSum, curIndex));
                    s.insert(curIndex);
                }
            }
        }
    }
    return sum;
}

int main()
{
    vector<vector<int> > v = {
            {1,10,10},{1,4,5},{2,3,6}
    };
    cout << kthSmallest(v, 7) << endl;
    return 0;
}