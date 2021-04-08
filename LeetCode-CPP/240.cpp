#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(const vector<int>& v, int target) {
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
        return end < 0 ? 0 : end;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        vector<int> head;
        for (const vector<int>& v : matrix) {
            head.emplace_back(v[0]);
        }
        int b = binarySearch(head, target), n = matrix[0].size() - 1;
        if (head[b] == target) {
            return true;
        }
        for (int i = b; i >= 0; --i) {
            if (matrix[i][n] < target) {
                return false;
            }
            if (matrix[i][binarySearch(matrix[i], target)] == target) {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int> > matrix;
    int target;
    int m,n,e;
    cin>>m;
    cin>>n;
    for(int i=0; i<m; i++)
    {
        vector<int> aRow;
        for(int j=0; j<n; j++)
        {
            cin>>e;
            aRow.push_back(e);
        }
        matrix.push_back(aRow);
    }
    cin>>target;
    bool res=Solution().searchMatrix(matrix,target);
    cout<<(res?"true":"false")<<endl;
    return 0;
}