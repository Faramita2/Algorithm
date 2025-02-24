#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maximumSum(vector<int>& nums) {
		unordered_map<int, int> m;
		int res = -1;
		for (int i = 0; i < nums.size(); i++) {
			int sum = sumOfDigits(nums[i]);
			if (m.count(sum)) m[sum] = nums[i] > nums[m[sum]] ? i : m[sum];
			else m[sum] = i;
		}
		for (int i = 0; i < nums.size(); i++) {
			int sum = sumOfDigits(nums[i]);
			if (m.count(sum) != 0 && m[sum] != i) {
				res = max(res, nums[i] + nums[m[sum]]);
			}
		}

		return res;
	}

	int maximumSum_(vector<int>& nums) {
		vector<int> m(82, -1);
		int res = -1;
		for (auto num : nums) {
			int sum = sumOfDigits(num);
			if (m[sum] == -1) {
				m[sum] = num;
			}
			else {
				res = max(res, m[sum] + num);
				m[sum] = max(num, m[sum]);
			}
		}
		
		return res;
	}


private:
	int sumOfDigits(int num) {
		int sum = 0;
		while (num > 0) {
			sum += num % 10;
			num /= 10;
		}
		return sum;
	}
};

int main()
{
	Solution s;

	vector<int> nums1 = { 18,43,36,13,7 };
	int e1 = 54;

	assert(e1 == s.maximumSum_(nums1));

	vector<int> nums2 = { 10,12,19,14 };
	int e2 = -1;

	assert(e2 == s.maximumSum_(nums2));

	vector<int> nums3 = { 368,369,307,304,384,138,90,279,35,396,114,328,251,364,300,191,438,467,183 };
	int e3 = 835;

	assert(e3 == s.maximumSum_(nums3));

	return 0;
}