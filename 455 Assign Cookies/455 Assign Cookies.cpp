#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int i = s.size() - 1, j = g.size() - 1;

        while (i >= 0) {
            while (j >= 0) {
                if (s[i] >= g[j--]) {
                    count++;
                    break;
                }
            }
            i--;
        }

        return count;
    }
};

int main()
{
    Solution solution;

    // Input: g = [1,2,3], s = [1,1]
    vector<int> g1 = {1, 2, 3};
    vector<int> s1 = {1, 1};
    cout << solution.findContentChildren(g1, s1) << endl;
    // Output: 1

    // Input: g = [1,2], s = [1,2,3]
    vector<int> g2 = {1, 2};
    vector<int> s2 = {1, 2, 3};
    cout << solution.findContentChildren(g2, s2) << endl;
    // Output: 2

    return 0;
}