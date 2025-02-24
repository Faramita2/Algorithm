#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int left = 0, right = 0, sum = 0, minLen = INT_MAX;
		for (int right = 0; right < nums.size(); right++) {
			sum += nums[right];
			while (sum >= target) {
				minLen = min(minLen, right - left + 1);
				sum -= nums[left++];
			}
		}
		return minLen == INT_MAX ? 0 : minLen;
	}
};

int main()
{
	Solution s;
	vector<int> nums1 = { 2,3,1,2,4,3 };
	int res1 = s.minSubArrayLen(7, nums1);
	assert(res1 == 2);
	vector<int> nums2 = { 1,4,4 };
	int res2 = s.minSubArrayLen(1, nums2);
	assert(res2 == 1);
	vector<int> nums3 = { 1,1,1,1,1,1,1,1 };
	int res3 = s.minSubArrayLen(11, nums3);
	assert(res3 == 0);
}