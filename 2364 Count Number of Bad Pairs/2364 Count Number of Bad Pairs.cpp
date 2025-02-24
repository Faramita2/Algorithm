#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	long long countBadPairs(vector<int>& nums) {
		unordered_map<int, int> m;
		long long count = 0;
		int n = nums.size();

		for (int i = 0; i < nums.size(); i++) {
			int key = nums[i] - i;
			count += m[key];
			m[key]++;
		}

		return (n * (n - 1) / 2) - count;
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 4,1,3,3 };
	long long res = s.countBadPairs(nums);
	cout << res << endl;
	vector<int> nums2 = { 1,2,3,4,5 };
	long long res2 = s.countBadPairs(nums2);
	cout << res2 << endl;

	return 0;
}