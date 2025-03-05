#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    long long coloredCells(int n)
    {
        return (long long)pow(n, 2) + pow(n - 1, 2);
    }

    long long coloredCells_mySolution(int n)
    {
        long long sum = 1;

        for (int i = 1; i <= n; i++) {
            sum += 4 * (i - 1);
        }

        return sum;
    }
};

int main()
{
    Solution solution;

    // Input: n = 1
    int  n1   = 1;
    auto res1 = solution.coloredCells(n1);
    cout << res1 << endl;
    // Output: 1

    // Input: n = 2
    int  n2   = 2;
    auto res2 = solution.coloredCells(n2);
    cout << res2 << endl;
    // Output: 5

    return 0;
}
