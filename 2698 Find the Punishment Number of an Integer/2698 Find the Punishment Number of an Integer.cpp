#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {

public:
	int punishmentNumber(int n) {
		if (n == 0) return 0;

		int addValue = canPartition(to_string(n * n), n, 0) ? (n * n) : 0;

		return addValue + punishmentNumber(n - 1);
	}

	int punishmentNumber(int n) {
		int punishmentNum = 0;
		for (int currentNum = 1; currentNum <= n; currentNum++) {
			int squareNum = currentNum * currentNum;
			string stringNum = to_string(squareNum);
			vector<vector<int>> memoArray(stringNum.size(), vector<int>(currentNum + 1, -1));

			if (findPartitions(0, 0, stringNum, currentNum, memoArray)) {
				punishmentNum += squareNum;
			}
		}

		return punishmentNum;
	}

private:
	bool findPartitions(int startIndex, int sum, string stringNum, int target, vector<vector<int>>& memo) {
		if (startIndex == stringNum.length()) return sum == target;

		if (sum > target) return false;

		if (memo[startIndex][sum] != -1) return memo[startIndex][sum];

		bool partitionFound = false;

		for (int currentIndex = startIndex; currentIndex < stringNum.length(); currentIndex++) {
			string currentString = stringNum.substr(startIndex, currentIndex - startIndex + 1);
			int addend = stoi(currentString);
			partitionFound = partitionFound || findPartitions(currentIndex + 1, sum + addend, stringNum, target, memo);
			if (partitionFound == true) return true;
		}
		return memo[startIndex][sum] = partitionFound;
	}

	bool canPartition(string num, int target, int start) {
		if (start == num.length()) return target == 0;

		int sum = 0;
		for (int i = start; i < num.length(); i++) {
			sum = sum * 10 + (num[i] - '0');
			if (sum > target) return false;
			if (canPartition(num, target - sum, i + 1)) return true;
		}

		return false;
	}
};

int main()
{
	Solution s;

	int n1 = 10;
	int res1 = s.punishmentNumber(n1);
	cout << res1 << endl;
	int n2 = 37;
	int res2 = s.punishmentNumber(n2);
	cout << res2 << endl;
	return 0;
}