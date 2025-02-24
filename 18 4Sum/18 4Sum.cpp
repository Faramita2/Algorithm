#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum_(vector<int>& nums, int target) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > target && nums[i] >= 0) break;
			if (i > 0 && nums[i - 1] == nums[i]) continue;
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) break;
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				int left = j + 1;
				int right = nums.size() - 1;
				while (left < right) {
					int sum = static_cast<long>(nums[i]) + nums[j] + nums[left] + nums[right];
					if (sum < target) left++;
					else if (sum > target) right--;
					else {
						res.push_back({ nums[i], nums[j], nums[left], nums[right] });
						left++;
						while (left < right && nums[left] == nums[left - 1]) left++;
					}
				}
			}
		}

		return res;
	}

	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res = kSum(nums, target, 0, 4);

		return res;
	}

private:
	vector<vector<int>> kSum(vector<int>& nums, long long target, int start, int k) {
		vector<vector<int>> res;
		if (start == nums.size()) return res;

		long long average = target / k;

		if (nums[start] > average || average > nums.back()) return res;

		if (k == 2) return twoSum(nums, target, start);

		for (int i = start; i < nums.size(); ++i) {
			if (i == start || nums[i - 1] != nums[i]) {
				for (auto& subset : kSum(nums, static_cast<long long>(target) - nums[i], i + 1, k - 1)) {
					res.push_back({ nums[i] });
					res.back().insert(end(res.back()), begin(subset), end(subset));
				}
			}
		}

		return res;
	}

	vector<vector<int>> twoSum(vector<int>& nums, long long target, int start) {
		vector<vector<int>> res;
		int lo = start, hi = int(nums.size()) - 1;

		while (lo < hi) {
			int sum = nums[lo] + nums[hi];
			if (sum < target || (lo > start && nums[lo] == nums[lo - 1])) ++lo;
			else if (sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1])) --hi;
			else res.push_back({ nums[lo++], nums[hi--] });
		}
		return res;
	}
};

void print2DArray(vector<vector<int>> res) {
	cout << "START: " << endl;
	for (const vector<int>& v : res) {
		cout << "\t";
		for (int i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
	cout << "END.\n\n";
}

int main()
{
	vector<int> nums = { 1,0,-1,0,-2,2 };
	int target = 0;
	Solution s;
	vector<vector<int>> res = s.fourSum_(nums, target);
	print2DArray(res);

	//nums = { 2,2,2,2,2 };
	//target = 8;
	//res = s.fourSum(nums, target);
	//print2DArray(res);

	//nums = { -2,-1,-1,1,1,2,2 };
	//target = 0;
	//res = s.fourSum(nums, target);
	//print2DArray(res);

	//nums = { 1,0,-1,0,-2,2 };
	//target = 0;
	//res = s.fourSum(nums, target);
	//print2DArray(res);

	//nums = { 1,-2,-5,-4,-3,3,3,5 };
	//target = -11;
	//res = s.fourSum(nums, target);
	//print2DArray(res);

	nums = { 1000000000,1000000000,1000000000,1000000000 };
	target = 0;
	res = s.fourSum_(nums, target);
	print2DArray(res);

	return 0;
}