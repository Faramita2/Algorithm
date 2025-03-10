#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  private:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

  public:
    long long countOfSubstrings(string word, int k)
    {
        long                     numValidSubstings = 0;
        int                      start             = 0;
        int                      end               = 0;
        unordered_map<char, int> vowelCount;
        int                      consonantCount = 0;

        vector<int> nextConsonant(word.size());
        int         nextConsonantIndex = word.size();
        for (int i = word.size() - 1; i >= 0; i--) {
            nextConsonant[i] = nextConsonantIndex;
            if (!isVowel(word[i])) {
                nextConsonantIndex = i;
            }
        }

        while (end < word.size()) {
            char newLetter = word[end];

            if (isVowel(newLetter)) {
                vowelCount[newLetter]++;
            } else {
                consonantCount++;
            }

            while (consonantCount > k) {
                char startLetter = word[start];
                if (isVowel(startLetter)) {
                    vowelCount[startLetter]--;
                    if (vowelCount[startLetter] == 0) {
                        vowelCount.erase(startLetter);
                    }
                } else {
                    consonantCount--;
                }
                start++;
            }

            while (start < word.size() && vowelCount.size() == 5 && consonantCount == k) {
                numValidSubstings += nextConsonant[end] - end;
                char startLetter = word[start];
                if (isVowel(startLetter)) {
                    vowelCount[startLetter]--;
                    if (vowelCount[startLetter] == 0) {
                        vowelCount.erase(startLetter);
                    }
                } else {
                    consonantCount--;
                }

                start++;
            }
            end++;
        }

        return numValidSubstings;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: word = "aeioqq", k = 1
    string word1 = "aeioqq";
    int    k1    = 1;
    cout << solution.countOfSubstrings(word1, k1) << endl;
    // Output: 0

    // Input: word = "aeiou", k = 0
    string word2 = "aeiou";
    int    k2    = 0;
    cout << solution.countOfSubstrings(word2, k2) << endl;
    // Output: 1

    // Input: word = "ieaouqqieaouqq", k = 1
    string word3 = "ieaouqqieaouqq";
    int    k3    = 1;
    cout << solution.countOfSubstrings(word3, k3) << endl;
    // Output: 3

    return 0;
}