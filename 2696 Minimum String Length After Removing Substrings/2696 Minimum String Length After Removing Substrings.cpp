#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> cs;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (cs.empty()) cs.push(c);
            else if ((c == 'B' && cs.top() == 'A') || (c == 'D' && cs.top() == 'C')) cs.pop();
            else cs.push(c);
        }
        return cs.size();
    }
};

int main()
{
    Solution s;
    assert(2 == s.minLength("ABFCACDB"));
    assert(5 == s.minLength("ACBBD"));

    return 0;
}