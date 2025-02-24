#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		if (nums[0] > 0)
			return res;
		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right) {
				int sum = nums[i] + nums[left] + nums[right];
				if (sum < 0) {
					left++;
				}
				else if (sum > 0)
					right--;
				else {
					res.push_back({ nums[i], nums[left], nums[right] });
					left++;
					while (left < right && nums[left] == nums[left - 1])
						left++;
				}
			}
		}
		return res;
	}
};

void print2DVector(vector<vector<int>>& vecs) {
	cout << "START\n";
	for (const vector<int>& v : vecs) {
		cout << "\t";
		for (int i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
	cout << "END\n";
}

int main()
{
	Solution s;
	vector<int> nums = { -1,0,1,2,-1,-4 };
	auto res = s.threeSum(nums);
	print2DVector(res);

	/*nums = { 0,1,1 };
	res = s.threeSum(nums);
	print2DVector(res);

	nums = { 0,0,0 };
	res = s.threeSum(nums);
	print2DVector(res);*/

	nums = { 0,0,0,0 };
	res = s.threeSum(nums);
	print2DVector(res);

	

	return 0;
}