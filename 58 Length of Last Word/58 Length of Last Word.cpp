#include <iostream>
#include <cassert>
#include <sstream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word, lastWord;

        while (ss >> word) lastWord = word;

        return lastWord.size();
    }
};

int main()
{
    string s1 = "Hello World";
    string s2 = "   fly me   to   the moon  ";
    string s3 = "luffy is still joyboy";

    Solution s;
    assert(s.lengthOfLastWord(s1) == 5);
    assert(s.lengthOfLastWord(s2) == 4);
    assert(s.lengthOfLastWord(s3) == 6);

    return 0;
}