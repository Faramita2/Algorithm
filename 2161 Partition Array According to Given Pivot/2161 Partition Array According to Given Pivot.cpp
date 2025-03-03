#include "../PerformanceMonitor/performance_monitor.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int         n = nums.size();
        vector<int> res(n);
        int         left = 0, right = n - 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                res[left++] = nums[i];
            }
            if (nums[n - 1 - i] > pivot) {
                res[right--] = nums[n - 1 - i];
            }
        }

        while (left <= right) {
            res[left++] = pivot;
        }

        return res;
    }
};

int main()
{

    Solution           solution;
    PerformanceMonitor monitor;

    // Input: nums = [9,12,5,10,14,3,10], pivot = 10
    vector<int> nums1  = {9, 12, 5, 10, 14, 3, 10};
    int         pivot1 = 10;
    monitor.start();
    auto res1 = solution.pivotArray(nums1, pivot1);
    monitor.stop();
    // Output: [9,5,3,10,10,12,14]
    for (int i : res1) {
        cout << i << " ";
    }
    cout << endl;

    // Input: nums = [-3,4,3,2], pivot = 2
    vector<int> nums2  = {-3, 4, 3, 2};
    int         pivot2 = 2;
    monitor.start();
    auto res2 = solution.pivotArray(nums2, pivot2);
    monitor.stop();
    // Output: [-3,2,4,3]
    for (int i : res2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}