#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool checkPowersOfThree(int n)
    {
        while (n != 0) {
            if (n % 3 == 2)
                return false;
            n /= 3;
        }
        return true;
    }
};

int main()
{
    Solution solution;

    // Input: n = 12
    int n1 = 12;
    cout << solution.checkPowersOfThree(n1) << endl;
    // Output: true;

    // Input: n = 91
    int n2 = 91;
    cout << solution.checkPowersOfThree(n2) << endl;
    // Output: true;

    // Input: n = 21
    int n3 = 21;
    cout << solution.checkPowersOfThree(n3) << endl;
    // Output: false;

    return 0;
}
