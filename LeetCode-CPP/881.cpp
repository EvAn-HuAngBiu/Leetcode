#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int p = 0, q = people.size() - 1;
    int cnt = 0;
    while (p < q) {
        ++cnt;
        ++p;
        if (people[p] + people[q] <= limit) {
            --q;
        }
    }
    return cnt;
}

int main()
{
    vector<int> v = {3, 5, 3, 4};
    cout << numRescueBoats(v, 5) << endl;
    return 0;
}