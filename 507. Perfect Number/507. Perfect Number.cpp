#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool checkPerfectNumber(int num)
    {
        if (num == 1)
            return false;

        int sum = 1;
        for (int i = 2; i < sqrt(num); i++) {
            if (num % i == 0) {
                sum += i;
                sum += num / i;
            }
        }

        return num == sum;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: num = 28
    int num1 = 28;
    cout << solution.checkPerfectNumber(num1) << endl;
    // Output: true

    // Input: num = 7
    int num2 = 7;
    cout << solution.checkPerfectNumber(num2) << endl;
    // Output: false

    return 0;
}