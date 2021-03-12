#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
using namespace std;

class Solution {
public:
    long long rectangleArea(vector<vector<long long>>& rectangles) {
        set<long long> x_vec_set;
        long long sumArea = 0, mod = 7 + 1e9;
        for (const auto &rectangle : rectangles){
            x_vec_set.insert(rectangle[0]);
            x_vec_set.insert(rectangle[2]);
        }
        vector<long long> xVec(x_vec_set.begin(), x_vec_set.end());

        for (long long i = xVec.size() - 2; i >= 0; --i){
            list<pair<long long, long long>> myList;
            for (const auto &rectangle : rectangles){
                if (rectangle[0] <= xVec[i] && rectangle[2] >= xVec[i + 1]){
                    addRange(myList, rectangle[1], rectangle[3]);
                }
            }

            long long distanceY = 0;
            for (const auto &item : myList){
                distanceY += item.second - item.first;
            }
            sumArea = (sumArea + (xVec[i + 1] - xVec[i]) * distanceY) % mod;
        }
        return sumArea;
    }

	void addRange(list<pair<long long, long long>> &myList, long long left, long long right) {
		auto it = myList.begin();
		while (it != myList.end() && it->second < left) {
			++it;
		}
		if (it == myList.end() || it->first > right) {
			myList.insert(it, make_pair(left, right));
		}
		else {
			it->first = min(it->first, left);
			it->second = max(it->second, right);
			auto beforeIt = it++;
			while (it != myList.end() && beforeIt->second >= it->first) {
				beforeIt->second = max(it->second, beforeIt->second);
				it = myList.erase(it);
			}
		}
	}
};

int main()
{
    long long n;
    cin >> n;
    vector<vector<long long>> v(n, vector<long long>(4));
    for (long long i = 0; i < n; ++i) {
        cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];
    }
    cout << Solution().rectangleArea(v) << endl;
    return 0;
}