#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<string> res;
    vector<string> m = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

  public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return res;
        backtracking(0, digits, "");
        return res;
    }

  private:
    void backtracking(int index, string digits, string s)
    {
        if (s.length() == digits.length()) {
            res.push_back(s);
            return;
        }

        int    idx = digits[index] - '0';
        string str = m[idx];
        for (int i = 0; i < str.length(); i++) {
            backtracking(index + 1, digits, s + str[i]);
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";

    Solution s;
    string   digits = "23";
    auto     res    = s.letterCombinations(digits);
    for (auto &s : res) {
        cout << s << endl;
    }

    return 0;
}