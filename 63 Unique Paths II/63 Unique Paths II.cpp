#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n - 1];
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
    vector<vector<int>> obstacleGrid1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << solution.uniquePathsWithObstacles(obstacleGrid1) << endl;
    // Ouput: 2

    // Input: obstacleGrid = [[0,1],[0,0]]
    vector<vector<int>> obstacleGrid2 = {{0, 1}, {0, 0}};
    cout << solution.uniquePathsWithObstacles(obstacleGrid2) << endl;
    // Ouput: 1

    return 0;
}