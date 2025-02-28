#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
    vector<string> res;
    vector<string> path;

  public:
    vector<string> restoreIpAddresses(const string &s)
    {
        backtracking(0, s, 0);
        return res;
    }

    void clear()
    {
        res.clear();
    }

  private:
    void backtracking(int startIndex, const string &s, int times)
    {
        if (startIndex == s.length() && times == 4) {
            string ip = path[0] + "." + path[1] + "." + path[2] + "." + path[3];
            res.push_back(ip);
            return;
        }
        for (int i = 1; i <= 3 && i <= s.length() - startIndex; i++) {
            auto tmp = s.substr(startIndex, i);
            if (!isValidIpFactor(tmp))
                continue;
            path.push_back(tmp);
            backtracking(startIndex + i, s, times + 1);
            path.pop_back();
        }
    }

    bool isValidIpFactor(const string &s)
    {
        if (s.empty() || s.length() > 3)
            return false;
        if (s.length() > 1 && s[0] == '0')
            return false;
        int value = stoi(s);
        return value >= 0 && value <= 255;
    }
};

int main()
{
    // Input: s = "25525511135"
    Solution s;
    // string   s1   = "25525511135";
    // auto     res1 = s.restoreIpAddresses(s1);
    // for (auto &str : res1) {
    //     cout << str << " ";
    // }
    // cout << endl;
    // s.clear();
    // // Output: ["255.255.11.135","255.255.111.35"]

    // // Input: s = "0000"
    // auto s2   = "0000";
    // auto res2 = s.restoreIpAddresses(s2);
    // for (auto &str : res2) {
    //     cout << str << " ";
    // }
    // cout << endl;
    // s.clear();
    // Output: ["0.0.0.0"]

    // Input: s = "101023"
    auto s3   = "010010";
    auto res3 = s.restoreIpAddresses(s3);
    for (auto &str : res3) {
        cout << str << " ";
    }
    cout << endl;
    // Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
    // 1.0.1.23 1.1.0.23 1.1.2.3 1.10.2.3 10.1.2.3
    return 0;
}