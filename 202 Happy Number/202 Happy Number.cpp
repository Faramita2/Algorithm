#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int sum = sumDigitsPower(n);
        while (sum != 1) {
            if (s.count(sum)) return false;
            s.insert(sum);
            sum = sumDigitsPower(sum);
        }
        return true;
    }

    bool isHappy_(int n) {
        int slow = sumDigitsPower(n);
        int fast = sumDigitsPower(sumDigitsPower(n));
        while (slow != fast) {
            slow = sumDigitsPower(slow);
            fast = sumDigitsPower(sumDigitsPower(fast));
        }

        return fast == 1;
    }

private:
    int sumDigitsPower(int n) {
        int res = 0;
        while (n > 0) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
};

int main()
{
    Solution s;
    assert(true == s.isHappy_(19));
    assert(false == s.isHappy_(2));
}