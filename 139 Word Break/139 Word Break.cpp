#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        unordered_set<string> st;
        for (auto &word : wordDict)
            st.insert(word);

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                string word = s.substr(j, i - j);
                if (st.find(word) != st.end() && dp[j] == true) {
                    dp[i] = true;
                }
            }
        }

        return dp.back();
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: s = "leetcode", wordDict = ["leet","code"]
    string         s1        = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    cout << solution.wordBreak(s1, wordDict1) << endl;
    // Output: true

    // Input: s = "applepenapple", wordDict = ["apple","pen"]
    string         s2        = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    cout << solution.wordBreak(s2, wordDict2) << endl;
    // Output: true

    // Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
    string         s3        = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << solution.wordBreak(s3, wordDict3) << endl;
    // Output: false

    return 0;
}