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
    int longestPalindromeSubseq(string s)
    {
        int                 len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        int                 maxLen = 0;
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 2) {
                        dp[i][j] = j - i + 1;
                    } else if (dp[i + 1][j - 1] != 0) {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
                maxLen = max(dp[i][j], maxLen);
            }
        }

        return maxLen;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: s = "bbbab"
    string s1 = "bbbab";
    cout << solution.longestPalindromeSubseq(s1) << endl;
    // Output: 4

    // Input: s = "cbbd"
    string s2 = "cbbd";
    cout << solution.longestPalindromeSubseq(s2) << endl;
    // Output: 2

    return 0;
}