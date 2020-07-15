#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int numTrees(int n) {
    vector<int> v(n + 1, 0);
    v[0] = v[1] = 1;
    for (int a = 2; a <= n; a++) {
        for (int i = 1; i <= a; i++) {
            v[a] += v[a - i] * v[i - 1];
        }
    }
    return v[n];
}

int main()
{
    cout << numTrees(3) << endl;
    return 0;
}