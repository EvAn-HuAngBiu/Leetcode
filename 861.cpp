#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

inline int max(int a, int b) {
    return a > b ? a : b;
}

int matrixScore(vector<vector<int>>& A) {
    int rlen = A.size(), clen = A[0].size();
    for (int i = 0; i < rlen; i++) {
        if (A[i][0] == 0) {
            for (int j = 0; j < clen; j++) {
                A[i][j] = !A[i][j];
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < clen; i++) {
        int curLine = 0;
        for (int j = 0; j < rlen; j++) {
            curLine += A[j][i];
        }
        sum += max(curLine, rlen - curLine) * pow(2, clen - i - 1);
    }
    
    return sum;
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> v(r);
    for (int i = 0; i < r; i++) {
        vector<int> vc(c);
        for (int j = 0; j < c; j++) {
            cin >> vc[j];
        }
        v[i] = vc;
    }
    cout << matrixScore(v) << endl;
    return 0;
}