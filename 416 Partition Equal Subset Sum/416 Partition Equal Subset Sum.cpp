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
    bool canPartition(vector<int> &nums)
    {
        int total = 0;
        for (int i : nums) {
            total += i;
        }
        if (total % 2 == 1)
            return false;
        int target = total / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                for (bool i : dp) {
                    cout << i << " ";
                }
                cout << endl;
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: nums = [1,5,11,5]
    vector<int> nums1 = {1, 5, 11, 5};
    cout << solution.canPartition(nums1) << endl;
    // Output: true;

    // Input: nums = [1,2,3,5]
    vector<int> nums2 = {1, 2, 3, 5};
    cout << solution.canPartition(nums2) << endl;
    // Output: false

    return 0;
}