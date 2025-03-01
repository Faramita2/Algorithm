#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<int> applyOperations(vector<int> &nums)
    {
        int n          = nums.size();
        int writeIndex = 0; // 用于记录非零元素写入的位置

        for (int i = 0; i < n; i++) {
            // 如果当前元素和下一个元素相等
            if (i + 1 < n && nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }

            // 将非零元素移到前面
            if (nums[i] != 0) {
                nums[writeIndex++] = nums[i];
            }
        }

        // 将剩余位置填充为零
        while (writeIndex < n) {
            nums[writeIndex++] = 0;
        }

        return nums;
    }
};

int main()
{
    Solution s;

    // Input: nums = [1,2,2,1,1,0]
    vector<int> nums1 = {1, 2, 2, 1, 1, 0};
    auto        res1  = s.applyOperations(nums1);
    for (int i : res1) {
        cout << i << " ";
    }
    cout << endl;
    // Output: [1,4,2,0,0,0]

    // Input: nums = [0,1]
    vector<int> nums2 = {0, 1};
    auto        res2  = s.applyOperations(nums2);
    for (int i : res2) {
        cout << i << " ";
    }
    cout << endl;
    // Output: [1,0]

    return 0;
}