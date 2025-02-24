#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            m[s.at(i)] = m.count(s.at(i)) ? ++m[s.at(i)] : 1;            
            m[t.at(i)] = m.count(t.at(i)) ? --m[t.at(i)] : -1;
        }
        for (const auto k : m) {
            if (k.second != 0) return false;
        }
        return true;
    }

    bool isAnagram_(string s, string t) {
        int m[26] = { 0 };
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            char sc = s.at(i) - 'a';
            char tc = t.at(i) - 'a';
            m[sc] = m[sc] != 0 ? ++m[sc] : 1;
            m[tc] = m[tc] != 0 ? --m[tc] : -1;
        }
        for (const auto i : m) {
            if (i != 0) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    assert(true == s.isAnagram_("anagram", "nagaram"));   
    assert(false == s.isAnagram_("rat", "car"));
    return 0;
}