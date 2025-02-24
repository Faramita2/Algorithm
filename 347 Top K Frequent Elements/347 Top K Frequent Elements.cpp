#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	vector<int> topKFrequent_(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		vector<int> res;

		for (int i : nums) {
			++m[i];
		}

		vector<pair<int, int>> vec(m.begin(), m.end());
		sort(vec.begin(), vec.end(),
			[](const pair<int, int>& a, const pair<int, int>& b) {
				return a.second > b.second;
			});

		for (int i = 0; i < k; i++) {
			res.push_back(vec[i].first);
		}

		return res;
	}

	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> res;
		unordered_map<int, int> m;

		auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
			return a.second > b.second;
			};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> minHeap(compare);

		for (int i : nums) {
			++m[i];
		}

		for (auto& p : m) {
			minHeap.push(p);
			if (minHeap.size() > k) minHeap.pop();
		}

		while (!minHeap.empty()) {
			res.push_back(minHeap.top().first);
			minHeap.pop();
		}

		return res;
	}
};

int main()
{
	Solution s;

	vector<int> nums1 = { 1,1,1,2,2,3 };
	int k1 = 2;
	for (int i : s.topKFrequent(nums1, k1)) {
		cout << i << " ";
	}
	cout << endl;

	vector<int> nums2 = { 1 };
	int k2 = 1;
	for (int i : s.topKFrequent(nums2, k2)) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}