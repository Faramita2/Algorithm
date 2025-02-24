#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		deque<int> q;

		for (int i = 0; i < k; i++) {
			while (!q.empty() && nums[q.back()] < nums[i]) {
				q.pop_back();
			}
			q.push_back(i);
		}
		res.push_back(nums[q.front()]);

		for (int i = k; i < nums.size(); i++) {
			if (!q.empty() && q.front() <= i - k) {
				q.pop_front();
			}

			while (!q.empty() && nums[q.back()] < nums[i]) {
				q.pop_back();
			}
			q.push_back(i);

			res.push_back(nums[q.front()]);
		}
		return res;
	}
};

int main()
{
	Solution s;

	vector<int> nums1 = { 1,3,-1,-3,5,3,6,7 };
	int k1 = 3;
	for (int i : s.maxSlidingWindow(nums1, k1)) {
		cout << i << " ";
	}
	cout << endl;

	vector<int> nums2 = { 1 };
	int k2 = 1;
	for (int i : s.maxSlidingWindow(nums2, k2)) {
		cout << i << " ";
	}
	cout << endl;

	vector<int> nums3 = { 3,3,1,2 };
	int k3 = 3;
	for (int i : s.maxSlidingWindow(nums3, k3)) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}