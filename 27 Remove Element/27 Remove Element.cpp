#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int  k = 0, len = nums.size();
		for (int i = 0; i < nums.size(); i++) {
			if (nums.at(i) == val) {
				k++;
			}
			else
				nums.at(i - k) = nums.at(i);
		}
		return len - k;
	}
};

int main()
{
	vector<int> nums = { 0,1,2,2,3,0,4,2 };
	auto s = make_unique<Solution>();
	int res = s->removeElement(nums, 2);
	assert(res == 5);

	return 0;
}