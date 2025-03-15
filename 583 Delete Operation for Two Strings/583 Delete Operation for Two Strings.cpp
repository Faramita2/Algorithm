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
    int minDistance(string word1, string word2)
    {
        int                 len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 0; i < len1 + 1; i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j < len2 + 1; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i < len1 + 1; i++) {
            for (int j = 1; j < len2 + 1; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1});
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

    // Input: word1 = "sea", word2 = "eat"
    string word1 = "sea", word2 = "eat";
    // cout << solution.minDistance(word1, word2) << endl;
    // Output: 2

    // Input: word1 = "leetcode", word2 = "etco"
    string word3 = "leetcode", word4 = "etco";
    // cout << solution.minDistance(word3, word4) << endl;
    // Output: 4

    // Input: word1 = "a", word2 = "b"
    string word5 = "a", word6 = "b";
    cout << solution.minDistance(word5, word6) << endl;
    // Output: 2

    return 0;
}