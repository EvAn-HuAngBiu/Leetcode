#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size == 0) {
            return {};
        } else if (size == 1) {
            return {-1};
        }
        map<int, int> list;
        for (int i = 0; i < size; i++) {
            list[intervals[i][0]] = i;
        }
        vector<int> result(size);
        for (int i = 0; i < size; i++) {
            auto it = list.lower_bound(intervals[i][1]);
            result[i] = (it == list.end() ? -1 : it->second);
        }
        return result;
    }
};

int main()
{
    vector<vector<int> > intervals;
    int n,start,end;
    cin>>n;
    for(int j=0; j<n; j++)
    {
        vector<int> aInterval;
        cin>>start>>end;
        aInterval.push_back(start);
        aInterval.push_back(end);
        intervals.push_back(aInterval);
    }
    vector<int> res=Solution().findRightInterval(intervals);
    for(int i=0; i<res.size(); i++)
    {
        if (i>0)
            cout<<" ";
        cout<<res[i];
    }
    return 0;
}