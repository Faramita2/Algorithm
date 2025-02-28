#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> res;
    vector<int> path;

public:
    vector<vector<int>> combine(int n, int k)
    {
        backtracking(1, n, k);
        return res;
    }

private:
    void backtracking(int startIndex, int num, int length)
    {
        if (path.size() == length)
        {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i <= num - (length - path.size()) + 1; i++)
        {
            path.push_back(i);
            backtracking(i + 1, num, length);
            path.pop_back();
        }
    }
};

int main()
{
    Solution s;
    auto res = s.combine(4, 2);
    for (auto &v : res)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}