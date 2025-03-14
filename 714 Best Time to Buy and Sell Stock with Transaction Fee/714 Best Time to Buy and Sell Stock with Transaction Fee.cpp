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
    int maxProfit(vector<int> &prices, int fee)
    {
        int size = prices.size();

        int idle = 0;
        int buy  = -prices[0];
        int sell = 0;

        for (int i = 1; i < size; i++) {
            int price = prices[i];

            int newIdle = max(idle, sell);
            int newBuy  = max(buy, max(idle - price, sell - price));
            int newSell = max(sell, buy + price - fee);

            idle = newIdle;
            buy  = newBuy;
            sell = newSell;
        }

        return max(idle, sell);
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: prices = [1,3,2,8,4,9], fee = 2
    vector<int> prices1 = {1, 3, 2, 8, 4, 9};
    int         fee1    = 2;
    cout << solution.maxProfit(prices1, fee1) << endl;
    // Output: 8

    // Input: prices = [1,3,7,5,10,3], fee = 3
    vector<int> prices2 = {1, 3, 7, 5, 10, 3};
    int         fee2    = 3;
    cout << solution.maxProfit(prices2, fee2) << endl;
    // Output: 6

    return 0;
}