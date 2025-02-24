#include <iostream>
#include <vector>
#include <queue>
#include <compare>
using namespace std;

class Solution {
public:
	class MinHeap {
		vector<int64_t> data;
	public:
		MinHeap(vector<int>& vec) {
			for (int num : vec) {
				data.push_back(static_cast<int64_t>(num));
			}

			for (int i = data.size() / 2 - 1; i >= 0; --i) {
				heapify(i);
			}
		}

		void push(int64_t x) {
			data.push_back(x);
			siftUp(data.size() - 1);
		}

		void pop() {
			swap(data[0], data[data.size() - 1]);
			data.pop_back();
			heapify(0);
		}

		int64_t top() {
			return data[0];
		}

	private:
		void siftUp(int i) {
			while (i > 0) {
				int parent = (i - 1) / 2;
				if (data[parent] <= data[i]) break;
				swap(data[parent], data[i]);
				i = parent;
			}
		}

		void heapify(int i) {
			while (true) {
				int left = i * 2 + 1;
				int right = i * 2 + 2;
				int smallest = i;

				if (left < data.size() && data[left] < data[smallest]) {
					smallest = left;
				}
				if (right < data.size() && data[right] < data[smallest]) {
					smallest = right;
				}
				if (smallest == i) break;

				swap(data[smallest], data[i]);
				i = smallest;
			}
		}
	};

	int minOperations(vector<int>& nums, int k) {
		int res = 0;
		MinHeap q(nums);
		while (q.top() < k) {
			auto a = q.top();
			q.pop();
			auto b = q.top();
			q.pop();
			q.push(min(a, b) * 2 + max(a, b));
			res++;
		}

		return res;
	}
};

int main()
{
	Solution s;

	//vector<int> nums1 = { 2,11,10,1,3 };
	//int k1 = 10;
	//s.minOperations(nums1, k1);

	//vector<int> nums2 = { 1,1,2,4,9 };
	//int k2 = 20;
	//s.minOperations(nums2, k2);

	vector<int> nums3 = { 999999999,999999999,999999999 };
	int k3 = 1000000000;
	s.minOperations(nums3, k3);

	return 0;
}