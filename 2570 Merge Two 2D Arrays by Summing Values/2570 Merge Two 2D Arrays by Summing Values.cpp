#include "../PerformanceMonitor/performance_monitor.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        vector<vector<int>> res;
        int                 i = 0;
        int                 j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            auto v1 = nums1[i];
            auto v2 = nums2[j];
            if (v1[0] == v2[0]) {
                res.push_back({v1[0], v1[1] + v2[1]});
                i++, j++;
            } else if (v1[0] < v2[0]) {
                res.push_back(v1);
                i++;
            } else {
                res.push_back(v2);
                j++;
            }
        }

        while (i < nums1.size())
            res.push_back(nums1[i++]);
        while (j < nums2.size())
            res.push_back(nums2[j++]);

        return res;
    }
};

int main()
{

    Solution           solution;
    PerformanceMonitor monitor;

    // Input: nums1 = {{1,2},{2,3},{4,5}}, nums2 = {{1,4},{3,2},{4,1}}
    vector<vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> nums2 = {{1, 4}, {3, 2}, {4, 1}};
    monitor.start();
    auto res1 = solution.mergeArrays(nums1, nums2);
    monitor.stop();
    for (auto &v : res1) {
        cout << "ID: " << v[0] << ", data: " << v[1] << endl;
    }
    // Output: {{1,6},{2,3},{3,2},{4,6}}

    // Input: nums1 = [[2,4],[3,6],[5,5]], nums2 = [[1,3],[4,3]]
    vector<vector<int>> nums3 = {{2, 4}, {3, 6}, {5, 5}};
    vector<vector<int>> nums4 = {{1, 3}, {4, 3}};
    monitor.start();
    auto res2 = solution.mergeArrays(nums3, nums4);
    monitor.stop();
    for (auto &v : res2) {
        cout << "ID: " << v[0] << ", data: " << v[1] << endl;
    }
    // Output: [[1,3],[2,4],[3,6],[4,3],[5,5]]

    // Input:
    // nums1 =
    // [[148,597],[165,623],[306,359],[349,566],[403,646],[420,381],[566,543],[730,209],[757,875],[788,208],[932,695]]
    // nums2 =
    // [[74,669],[87,399],[89,165],[99,749],[122,401],[138,16],[144,714],[148,206],[177,948],[211,653],[285,775],[309,289],[349,396],[386,831],[403,318],[405,119],[420,153],[468,433],[504,101],[566,128],[603,688],[618,628],[622,586],[641,46],[653,922],[672,772],[691,823],[693,900],[756,878],[757,952],[770,795],[806,118],[813,88],[919,501],[935,253],[982,385]]

    vector<vector<int>> nums5 = {{148, 597}, {165, 623}, {306, 359}, {349, 566},
                                 {403, 646}, {420, 381}, {566, 543}, {730, 209},
                                 {757, 875}, {788, 208}, {932, 695}};
    vector<vector<int>> nums6 = {
        {74, 669},  {87, 399},  {89, 165},  {99, 749},  {122, 401}, {138, 16},
        {144, 714}, {148, 206}, {177, 948}, {211, 653}, {285, 775}, {309, 289},
        {349, 396}, {386, 831}, {403, 318}, {405, 119}, {420, 153}, {468, 433},
        {504, 101}, {566, 128}, {603, 688}, {618, 628}, {622, 586}, {641, 46},
        {653, 922}, {672, 772}, {691, 823}, {693, 900}, {756, 878}, {757, 952},
        {770, 795}, {806, 118}, {813, 88},  {919, 501}, {935, 253}, {982, 385}};
    monitor.start();
    auto res3 = solution.mergeArrays(nums5, nums6);
    monitor.stop();
    for (auto &v : res3) {
        cout << "ID: " << v[0] << ", data: " << v[1] << endl;
    }
    // Output: [[1,3],[2,4],[3,6],[4,3],[5,5]]

    return 0;
}