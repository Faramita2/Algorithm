#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum)
            return 0;
        if ((sum + target) % 2 == 1)
            return 0;

        int         n = (sum + target) / 2;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        // objects
        for (int i = 0; i < nums.size(); i++) {
            // values
            for (int j = n; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp.back();
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: nums = [1,1,1,1,1], target = 3
    vector<int> nums1   = {1, 1, 1, 1, 1};
    int         target1 = 3;
    cout << solution.findTargetSumWays(nums1, target1) << endl;
    // Output: 5

    // Input: 1
    vector<int> nums2   = {1};
    int         target2 = 1;
    cout << solution.findTargetSumWays(nums2, target2) << endl;
    // Output: 1

    return 0;
}