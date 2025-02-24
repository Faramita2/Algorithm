#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		int left = 0, right = n - 1, top = 0, bottom = n - 1;
		int num = 1;

		while (left <= right && top <= bottom) {
			for (int i = left; i <= right; i++) {
				res[top][i] = num++;
			}
			top++;

			for (int i = top; i <= bottom; i++) {
				res[i][right] = num++;
			}
			right--;

			if (left <= right) {
				for (int i = right; i >= left; i--) {
					res[bottom][i] = num++;
				}
				bottom--;
			}

			if (top <= bottom) {
				for (int i = bottom; i >= top; i--) {
					res[i][left] = num++;
				}
				left++;
			}
		}

		return res;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> res = s.generateMatrix(3);
	for (const vector<int> v : res) {
		for (const int i : v) {
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}