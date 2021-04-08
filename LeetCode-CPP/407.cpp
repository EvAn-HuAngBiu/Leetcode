#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

struct Point {
    int x, y, z;
    Point() {}
    Point(int x, int y, int z) : x(x), y(y), z(z) {}

    bool operator()(const Point& p1, const Point& p2) {
        if (p1.z == p2.z) {
            if (p1.x == p2.x) {
                return p1.y > p2.y;
            }
            return p1.x > p2.x;
        }
        return p1.z > p2.z;
    }
};

int trapRainWater(vector<vector<int>>& heightMap) {
    priority_queue<Point, vector<Point>, Point> pq;
    bool visited[120][120] = {false};
    int x_step[] = {0, 0, 1, -1};
    int y_step[] = {1, -1, 0, 0};
    int m = heightMap.size(), n = heightMap[0].size();
    for (int i = 0; i < m; i++) {
        visited[i][0] = visited[i][n - 1] = true;
        pq.push(Point(i, 0, heightMap[i][0]));
        pq.push(Point(i, n - 1, heightMap[i][n - 1]));
    }
    for (int i = 1; i < n - 1; i++) {
        visited[0][i] = visited[m - 1][i] = true;
        pq.push(Point(0, i, heightMap[0][i]));
        pq.push(Point(m - 1, i, heightMap[m - 1][i]));
    }

    int result = 0, max = INT_MIN;
    while (!pq.empty()) {
        Point top = pq.top();
        pq.pop();
        max = (max > top.z ? max : top.z);
        for (int i = 0; i < 4; i++) {
            int nx = top.x + x_step[i], ny = top.y + y_step[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                if (heightMap[nx][ny] < max) {
                    result += max - heightMap[nx][ny];
                }
                visited[nx][ny] = true;
                pq.push(Point(nx, ny, heightMap[nx][ny]));
            }
        }
    }
    return result;
}

int main()
{
    vector<vector<int> > v = {
            {12,13,1,12},{13,4,13,12},{13,8,10,12},{12,13,12,12},{13,13,13,13}
    };
    cout << trapRainWater(v) << endl;
    return 0;
}