#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		unordered_map<int, int> m;

		for (int i = 0; i < nums.size(); i++) {
			int num = nums[i];
			int remain = target - num;
			if (m.count(remain))
				return { i, m[remain] };
			else m[num] = i;
		}

		return res;
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 2,7,11,15 };
	int target = 9;
	vector<int> res = s.twoSum(nums, target);
	for (int n : res) {
		cout << n << " ";
	}
	cout << endl;

	vector<int> nums1 = { 3,2,4 };
	int target2 = 6;
	vector<int> res2 = s.twoSum(nums1, target2);
	for (int n : res2) {
		cout << n << " ";
	}
	cout << endl;

	vector<int> nums2 = { 3,3 };
	int target3 = 6;
	vector<int> res3 = s.twoSum(nums2, target3);
	for (int n : res3) {
		cout << n << " ";
	}
	cout << endl;

	return 0;
}