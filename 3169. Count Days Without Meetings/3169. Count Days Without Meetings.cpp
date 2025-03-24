#include "../PerformanceMonitor/performance_monitor.h"
#include "../BinaryTreeUtil/binary_tree_util.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
      int countDays(int days, vector<vector<int>>& meetings) {
          map<int, int> dayMap;
          int prefixSum = 0, freeDays = 0, previousDay = days;
          bool hasGap = false;
  
          for (auto& meeting : meetings) {
              // Set first day of meetings
              previousDay = min(previousDay, meeting[0]);
  
              // Process start and end of meeting
              dayMap[meeting[0]]++;
              dayMap[meeting[1] + 1]--;
          }
  
          // Add all days before the first day of meetings
          freeDays += (previousDay - 1);
          for (auto& day : dayMap) {
              int currentDay = day.first;
              // Add current range of days without a meeting
              if (prefixSum == 0) {
                  freeDays += currentDay - previousDay;
              }
              prefixSum += day.second;
              previousDay = currentDay;
          }
  
          // Add all days after the last day of meetings
          freeDays += days - previousDay + 1;
          return freeDays;
      }
  };

int main() {
    Solution solution;
    PerformanceMonitor monitor;

    // Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
    int days1 = 10;
    vector<vector<int>> meetings1 = {{5, 7}, {1, 3}, {9, 10}};
    cout << solution.countDays(days1, meetings1) << endl;

    int days2 = 5;
    vector<vector<int>> meetings2 = {{2, 4}, {1, 3}};
    // cout << solution.countDays(days2, meetings2) << endl;


    return 0;
}