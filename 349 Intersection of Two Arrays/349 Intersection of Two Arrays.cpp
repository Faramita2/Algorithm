#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		vector<int> res;
		int p1 = 0;
		int p2 = 0;
		int last = -1;
		while (p1 < nums1.size() && p2 < nums2.size()) {
			int n1 = nums1[p1];
			int n2 = nums2[p2];
			if (last != n1 && n1 == n2) {
				last = n1;
				p1++;
				p2++;
				res.push_back(last);
			}
			else if (n1 < n2) {
				p1++;
			}
			else {
				p2++;
			}
		}
		return res;
	}

	vector<int> intersection_(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		unordered_set<int> s1(nums1.begin(), nums1.end());		
		unordered_set<int> s2(nums2.begin(), nums2.end());
		for (int i : s1) {
			if (s2.count(i)) res.push_back(i);
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> nums1 = { 1,2,2,1 };
	vector<int> nums2 = { 2,2 };
	vector<int> res = s.intersection_(nums1, nums2);
	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;


	vector<int> nums3 = { 4,9,5 };
	vector<int> nums4 = { 9,4,9,8,4 };
	vector<int> res1 = s.intersection_(nums3, nums4);
	for (int i : res1) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
