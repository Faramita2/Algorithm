#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int mid = (lo + hi) / 2;
        while (lo <= hi) {
            int tmp = nums.at(mid);
            if (tmp == target) return mid;
            else if (tmp > target) hi = mid - 1;
            else lo = mid + 1;
            mid = (lo + hi) / 2;
        }

        return -1;
    }
};

int main()
{
	Solution s;
    vector<int> nums = { -1,0,3,5,9,12 };
	int res = s.search(nums, 9);
    assert(res == 4);
}