#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		unordered_map<int, int> sumAB;
		for (int a : nums1) {
			for (int b : nums2) {
				++sumAB[a + b];
			}
		}
		int res = 0;
		for (int c : nums3) {
			for (int d : nums4) {
				int target = -(c + d);
				if (sumAB.count(target)) res += sumAB[target];
			}
		}
		return res;
	}
};

int main()
{
	vector<int> nums1 = { 1, 2 };
	vector<int> nums2 = { -2, -1 };
	vector<int> nums3 = { -1, 2 };
	vector<int> nums4 = { 0, 2 };

	Solution s;
	assert(2 == s.fourSumCount(nums1, nums2, nums3, nums4));

	nums1 = { 0 };
	nums2 = { 0 };
	nums3 = { 0 };
	nums4 = { 0 };
	assert(1 == s.fourSumCount(nums1, nums2, nums3, nums4));

	return 0;
}