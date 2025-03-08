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
    int minimumRecolors(string blocks, int k)
    {
        int currentWhiteCount = 0;
        for (int i = 0; i < k; i++) {
            currentWhiteCount += blocks[i] == 'W' ? 1 : 0;
        }

        int minWhiteCount = currentWhiteCount;

        for (int i = k; i < blocks.size(); i++) {
            currentWhiteCount += blocks[i] == 'W' ? 1 : 0;
            currentWhiteCount += blocks[i - k] == 'W' ? -1 : 0;
            minWhiteCount = min(minWhiteCount, currentWhiteCount);
        }

        return minWhiteCount;
    }

    int minimumRecolors_(string blocks, int k)
    {
        vector<string> allPossibleStrings;
        for (int i = 0; i <= blocks.size() - k; i++) {
            allPossibleStrings.push_back(blocks.substr(i, k));
        }

        int minWhiteCount = INT_MAX;
        for (auto &s : allPossibleStrings) {
            int whiteCount = 0;
            for (auto c : s) {
                whiteCount += c == 'W' ? 1 : 0;
            }
            minWhiteCount = min(minWhiteCount, whiteCount);
        }

        return minWhiteCount;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    ifstream inputFile("input");
    if (!inputFile.is_open()) {
        cerr << "Error, cannot open file \"input\"" << endl;
    }

    string line;

    vector<pair<string, int>> testCases;
    while (getline(inputFile, line)) {
        istringstream iss(line);

        string blocks;
        int    k;

        iss >> blocks >> k;
        testCases.push_back({blocks, k});
    }

    for (int i = 0; i < testCases.size(); i++) {
        auto testCase = testCases[i];
        monitor.start();
        auto res = solution.minimumRecolors(testCase.first, testCase.second);
        monitor.stop();
        cout << "Input: blocks = " << testCase.first << ", k = " << testCase.second << endl;
        cout << "Output: " << res << endl;
    }

    return 0;
}