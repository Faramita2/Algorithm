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
    int numDistinct(string s, string t)
    {
        int len1 = s.length(), len2 = t.length();

        vector<vector<unsigned long>> dp(len1 + 1, vector<unsigned long>(len2 + 1, 0));
        for (int i = 0; i < len1 + 1; i++) {
            dp[i][0] = 1;
        }

        for (int j = 0; j < len2 + 1; j++) {
            dp[0][j] = 0;
        }

        dp[0][0] = 1;

        for (int i = 1; i < len1 + 1; i++) {
            for (int j = 1; j < len2 + 1; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[len1][len2];
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: s = "rabbbit", t = "rabbit"
    string s1 = "rabbbit", t1 = "rabbit";
    cout << solution.numDistinct(s1, t1) << endl;
    // Output: 3

    // Input: s = "babgbag", t = "bag"
    string s2 = "babgbag", t2 = "bag";
    cout << solution.numDistinct(s2, t2) << endl;
    // Output: 5

    return 0;
}