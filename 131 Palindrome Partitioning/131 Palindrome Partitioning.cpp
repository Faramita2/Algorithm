#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<string>> res;
    vector<string>         path;

  public:
    vector<vector<string>> partition(const string &s)
    {
        backtracking(0, s);
        return res;
    }

  private:
    void backtracking(int startIndex, const string &str)
    {
        if (startIndex == str.length()) {
            res.push_back(path);
            return;
        }

        for (int j = 1; j <= str.length() - startIndex; j++) {
            auto tmp = str.substr(startIndex, j);
            if (!isPalindrome(tmp))
                continue;
            path.push_back(tmp);
            backtracking(startIndex + j, str);
            path.pop_back();
        }
    }

    bool isPalindrome(const string &s)
    {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
};

int main()
{
    // Input: s = "aab"
    string   str = "aab";
    Solution so;
    auto     res = so.partition(str);
    for (auto &v : res) {
        for (auto &s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
    // Output: [["a","a","b"],["aa","b"]]

    // Input: s = "a"

    Solution so2;
    string   str2 = "a";
    res           = so2.partition(str2);
    for (auto &v : res) {
        for (auto &s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
    // Output: [["a"]]

    return 0;
}