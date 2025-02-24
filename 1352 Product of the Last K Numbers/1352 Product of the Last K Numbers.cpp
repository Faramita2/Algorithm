#include <iostream>
#include <vector>
using namespace std;

class ProductOfNumbers {
    vector<int> data;
public:
    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) data.clear();
        else if (data.empty()) data.push_back(num);
        else data.push_back(data.back() * num);
    }

    int getProduct(int k) {
        int size = data.size();
        if (k > size) return 0;
        int delta = size - k;
        return delta == 0 ? data.back() : data.back() / data[delta - 1];
    }
};


int main()
{
    ProductOfNumbers productOfNumbers;
    productOfNumbers.add(3);        // [3] 3
    productOfNumbers.add(0);        // [3,0] 
    productOfNumbers.add(2);        // [3,0,2] 2
    productOfNumbers.add(5);        // [3,0,2,5] 2 10
    productOfNumbers.add(4);        // [3,0,2,5,4] 2 10 40   
    int res = productOfNumbers.getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
    res = productOfNumbers.getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
    res = productOfNumbers.getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
    productOfNumbers.add(8);        // [3,0,2,5,4,8] 
    res = productOfNumbers.getProduct(2); // return 32. The product of the last 2 numbers is 4 * 8 = 32 
}