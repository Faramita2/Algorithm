#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    int findTheWinner(int n, int k)
    {
        int res = 0;
        for (int i = 2; i <= n; i++) {
            res = (res + k) % i;
        }
        return res + 1;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: n = 5, k = 2
    int n1 = 5, k1 = 2;
    cout << solution.findTheWinner(n1, k1) << endl;
    // Output: 3

    // Input: n = 6, k = 5
    int n2 = 6, k2 = 5;
    cout << solution.findTheWinner(n2, k2) << endl;
    // Output: 1

    return 0;
}