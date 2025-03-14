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
    int lengthOfLIS(vector<int> &nums)
    {
        int size = nums.size();

        vector<int> dp(size, 1);

        int maxLen = 1;
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
                maxLen = max(dp[i], maxLen);
            }
        }

        return maxLen;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: nums = [10,9,2,5,3,7,101,18]
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << solution.lengthOfLIS(nums1) << endl;
    // Output: 4

    // Input: nums = [0,1,0,3,2,3]
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    cout << solution.lengthOfLIS(nums2) << endl;
    // Output: 4

    // Input: nums = [7,7,7,7,7,7,7]
    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    cout << solution.lengthOfLIS(nums3) << endl;
    // Output: 1

    return 0;
}