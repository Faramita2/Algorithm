#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        string result;
        for (const char c : s) {
            if (isalpha(c)) result += c;
            else {
                result.pop_back();
            }
        }

        return result;
    }
};

int main()
{
    cout << "Hello World!\n";
}