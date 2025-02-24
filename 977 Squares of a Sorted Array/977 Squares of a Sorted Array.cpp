#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int left = 0, right = nums.size() - 1;
        for (int i = nums.size() - 1; i >=0; i--) {
            int lvalue = nums.at(left) * nums.at(left);
            int rvalue = nums.at(right) * nums.at(right);
            if (lvalue > rvalue) {
                result.at(i) = lvalue;
                left++;
            }
            else {
                result.at(i) = rvalue;
                right--;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { -4,-1,0,3,10 };
    vector<int> expected = { 0,1,9,16,100 };
    vector<int> result = s.sortedSquares(nums);

    for (int i = 0; i < result.size(); i++) {
        assert(result[i] == expected[i]);
    }

    return 0;
}