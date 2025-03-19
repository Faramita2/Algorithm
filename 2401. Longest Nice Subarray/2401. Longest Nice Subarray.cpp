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
    int longestNiceSubarray(vector<int> &nums)
    {
        int usedBits    = 0;
        int windowStart = 0;
        int maxLength   = 0;
        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            while ((usedBits & nums[windowEnd]) != 0) {
                usedBits ^= nums[windowStart];
                windowStart++;
            }

            usedBits |= nums[windowEnd];

            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }

        return maxLength;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: nums = [1,3,8,48,10]
    vector<int> nums1 = {1, 3, 8, 48, 10};
    cout << solution.longestNiceSubarray(nums1) << endl;
    // Output: 3

    // Input: nums = [3,1,5,11,13]
    vector<int> nums2 = {3, 1, 5, 11, 13};
    cout << solution.longestNiceSubarray(nums2) << endl;
    // Output: 1

    return 0;
}