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
    int longestCommonSubsequence(string text1, string text2)
    {
        int                 len1 = text1.length(), len2 = text2.length();
        int                 longest = 0;
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                longest = max(longest, dp[i][j]);
            }
        }

        return longest;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: text1 = "abcde", text2 = "ace"
    string text1 = "abcde", text2 = "ace";
    cout << solution.longestCommonSubsequence(text1, text2) << endl;
    // Output: 3

    // Input: text1 = "abc", text2 = "abc"
    string text3 = "abc", text4 = "abc";
    cout << solution.longestCommonSubsequence(text3, text4) << endl;
    // Output: 3

    // Input: text1 = "abc", text2 = "def"
    string text5 = "abc", text6 = "def";
    cout << solution.longestCommonSubsequence(text5, text6) << endl;
    // Output: 0

    return 0;
}