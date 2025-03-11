#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto &str : strs) {
            int zeroCount = 0;
            int oneCount  = 0;
            for (char c : str) {
                if (c == '0')
                    zeroCount++;
                else
                    oneCount++;
            }
            for (int i = m; i >= zeroCount; i--) {
                for (int j = n; j >= oneCount; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroCount][j - oneCount] + 1);
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
    vector<string> strs1 = {"10", "0001", "111001", "1", "0"};
    int            m1    = 5;
    int            n1    = 3;
    cout << solution.findMaxForm(strs1, m1, n1) << endl;
    // Output: 4

    // Input: strs = ["10","0","1"], m = 1, n = 1
    vector<string> strs2 = {"10", "0", "1"};
    int            m2    = 1;
    int            n2    = 1;
    cout << solution.findMaxForm(strs2, m2, n2) << endl;
    // Output: 2

    return 0;
}