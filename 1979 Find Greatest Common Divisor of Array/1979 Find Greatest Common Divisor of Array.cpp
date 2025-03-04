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
    int findGCD(vector<int> &nums)
    {
        uint32_t maximum = 0;
        uint32_t minimum = UINT32_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maximum)
                maximum = nums[i];
            if (nums[i] < minimum)
                minimum = nums[i];
        }
        return gcd(maximum, minimum);
    }

  private:
    uint32_t gcd(uint32_t a, uint32_t b)
    {
        while (b != 0) {
            int next = b;
            b        = a % b;
            a        = next;
        }
        return a;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    return 0;
}