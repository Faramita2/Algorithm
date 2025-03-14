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
        int size = prices.size();

        int idle     = 0;
        int buy      = -prices[0];
        int sell     = 0;
        int colddown = 0;

        // 0     1    2     3
        // idle, buy, sell, colddown
        for (int i = 1; i < size; i++) {
            int price   = prices[i];
            int newIdle = idle;
            // 1. yesterday is "buy" state, keep this state today
            // 2. yesterday is "idle" state, and then buy stock today
            // 3. yesterday is "colddown" state, buy new stock today
            int newBuy = max(buy, max(idle - price, colddown - price));
            // yesterday is "sell" state, or today sell stock bought before
            int newSell = max(sell, buy + price);
            // only update when yesterday was "sell"
            int newColddown = sell;

            idle     = newIdle;
            buy      = newBuy;
            sell     = newSell;
            colddown = newColddown;
        }

        return max(idle, max(sell, colddown));
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: prices = [1,2,3,0,2]
    vector<int> prices1 = {1, 2, 3, 0, 2};
    cout << solution.maxProfit(prices1) << endl;
    // Output: 3

    // Input: prices = [1]
    vector<int> prices2 = {1};
    cout << solution.maxProfit(prices2) << endl;
    // Output: 0

    // Input: prices = {1,2}
    vector<int> prices3 = {1, 2};
    cout << solution.maxProfit(prices3) << endl;
    // Output: 1

    return 0;
}