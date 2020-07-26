#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    const int INF = 10000;
    inline int min(int a, int b) {
        return a < b ? a : b;
    }
    inline int max(int a, int b) {
        return a > b ? a : b;
    }
    // Floyd
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, INF));
        for (int i = 0; i <= N; i++) {
            dp[i][i] = 0;
        }
        for (const vector<int>& time : times) {
            dp[time[0]][time[1]] = time[2];
        }
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        int result = 0;
        for (int i = 1; i <= N; i++) {
            result = max(result, dp[K][i]);
        }
        return result == INF ? -1 : result;
    }
};

int main()
{
    int N,M,K;
    vector<vector<int> > times;
    cin>>N>>M>>K;
    int u,v,w;
    for(int i=0; i<M; i++)
    {
        cin>>u>>v>>w;
        vector<int> time;
        time.push_back(u);
        time.push_back(v);
        time.push_back(w);
        times.push_back(time);
    }
    int res=Solution().networkDelayTime(times,N,K);
    cout<<res<<endl;
}