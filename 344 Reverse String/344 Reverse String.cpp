#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            /*char tmp = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = tmp;*/
            swap(s[i], s[s.size() - 1 - i]);
        }
    }
};

int main()
{
    Solution solution;
    vector<char> s = { 'h', 'e', 'l', 'l', 'o'};
    solution.reverseString(s);
    for (auto c : s) {
        cout << c;
    }
    cout << endl;

    return 0;
}