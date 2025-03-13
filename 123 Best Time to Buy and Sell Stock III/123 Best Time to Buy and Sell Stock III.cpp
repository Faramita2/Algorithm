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
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 1)
            return 0;

        int idle         = 0;
        int firstHold    = -prices[0];
        int firstUnhold  = 0;
        int secondHold   = -prices[0];
        int secondUnhold = 0;

        for (int i = 1; i < prices.size(); i++) {
            int price           = prices[i];
            int newIdle         = idle;
            int newFirstHold    = max(firstHold, idle - price);
            int newFirstUnhold  = max(firstUnhold, firstHold + price);
            int newSecondHold   = max(secondHold, firstUnhold - price);
            int newSecondUnhold = max(secondUnhold, secondHold + price);
            idle                = newIdle;
            firstHold           = newFirstHold;
            firstUnhold         = newFirstUnhold;
            secondHold          = newSecondHold;
            secondUnhold        = newSecondUnhold;
        }
        return max(idle, max(firstUnhold, secondUnhold));
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: prices = [3,3,5,0,0,3,1,4]
    vector<int> prices1 = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << solution.maxProfit(prices1) << endl;
    // Output: 6

    // Input: prices = [1,2,3,4,5]
    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << solution.maxProfit(prices2) << endl;
    // Output: 4

    // Input: prices = [7,6,4,3,1]
    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << solution.maxProfit(prices3) << endl;
    // Output: 0

    return 0;
}