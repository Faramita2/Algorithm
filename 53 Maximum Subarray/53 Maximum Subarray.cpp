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
    int maxSubArray(vector<int> &nums)
    {
        int sum    = 0;
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum    = max(nums[i], sum + nums[i]);
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << solution.maxSubArray(nums1) << endl;
    // Output: 6

    // Input: nums = [1]
    vector<int> nums2 = {1};
    cout << solution.maxSubArray(nums2) << endl;
    // Output: 1

    // Input: nums = [5,4,-1,7,8]
    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << solution.maxSubArray(nums3) << endl;
    // Output: 23

    return 0;
}