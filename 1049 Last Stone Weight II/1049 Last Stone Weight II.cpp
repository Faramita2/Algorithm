#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
  public:
    int lastStoneWeightII(vector<int> &stones)
    {
        vector<int> dp(1501, 0);
        int         n   = stones.size();
        int         sum = accumulate(stones.begin(), stones.end(), 0);
        for (int i = 0; i < n; i++) {
            for (int j = sum / 2; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return sum - dp[sum / 2] - dp[sum / 2];
    }
};

int main()
{
    Solution solution;
    // Input: stones = [2,7,4,1,8,1]
    vector<int> nums1 = {2, 7, 4, 1, 8, 1};
    cout << solution.lastStoneWeightII(nums1) << endl;
    // Output: 1

    // Input: stones = [31,26,33,21,40]
    vector<int> nums2 = {31, 26, 33, 21, 40};
    cout << solution.lastStoneWeightII(nums2) << endl;
    // Output: 5

    return 0;
}