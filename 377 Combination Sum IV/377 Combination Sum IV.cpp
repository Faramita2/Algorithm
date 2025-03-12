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
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= target; j++) {
            for (int i = 0; i < nums.size(); i++) {
                dp[j] += j >= nums[i] ? dp[j - nums[i]] : 0;
            }
        }
        return dp.back();
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: nums = [1,2,3], target = 4
    vector<int> nums1   = {1, 2, 3};
    int         target1 = 4;
    cout << solution.combinationSum4(nums1, target1) << endl;
    // Output: 7

    // Input: nums = [9], target = 3
    vector<int> nums2   = {9};
    int         target2 = 3;
    cout << solution.combinationSum4(nums2, target2) << endl;
    // Output: 0

    return 0;
}