#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<bool> isPrimeNum(right + 1, true);
        isPrimeNum[0] = isPrimeNum[1] = false;

        for (int i = 2; i * i <= right; i++) {
            if (isPrimeNum[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrimeNum[j] = false;
                }
            }
        }

        vector<int> primes;
        for (int num = max(2, left); num <= right; num++) {
            if (isPrimeNum[num]) {
                primes.push_back(num);
            }
        }

        vector<int> res = {-1, -1};
        if (primes.size() < 2)
            return res;

        int minGap = INT_MAX;
        for (int i = 0; i < primes.size() - 1; i++) {
            int gap = primes[i + 1] - primes[i];
            if (gap < minGap) {
                res    = {primes[i], primes[i + 1]};
                minGap = gap;
            }
        }

        return res;
    }

  private:
    bool isPrime(int num)
    {
        if (num <= 1)
            return false;
        if (num == 2 || num == 3)
            return true;
        if (num % 2 == 0 || num % 3 == 0)
            return false;

        int limit = sqrt(num);
        for (int i = 5; i <= limit; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    // Input: left = 10, right = 19
    int  left1 = 10, right1 = 19;
    auto res1 = solution.closestPrimes(left1, right1);
    cout << "num1: " << res1[0] << ", num2: " << res1[1] << endl;
    // Output: [11,13]

    // Input: left = 4, right = 6
    int  left2 = 4, right2 = 6;
    auto res2 = solution.closestPrimes(left2, right2);
    cout << "num1: " << res2[0] << ", num2: " << res2[1] << endl;
    // Output: [-1,-1]

    return 0;
}