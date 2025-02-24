#include <iostream>
#include <unordered_map>
#include <queue>
#include <cassert>
using namespace std;

class NumberContainers {
public:
	unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;
	unordered_map<int, int> d;

	NumberContainers() {}

	// Fills the container at index with the number. 
	// If there is already a number at that index, replace it.
	void change(int index, int number) {
		if (d.count(index) && d[index] == number) return;
		d[index] = number;
		m[number].push(index);
	}

	// Returns the smallest index for the given number, 
	// or -1 if there is no index that is filled by number in the system.
	int find(int number) {
		if (!m.count(number)) return -1;
		auto& pq = m[number];
		while (!pq.empty() && d[pq.top()] != number) pq.pop();
		return pq.empty() ? -1 : pq.top();
	}
};

int main()
{
	auto nc = make_unique<NumberContainers>();
	assert(-1 == nc->find(10)); // There is no index that is filled with number 10. Therefore, we return -1.
	nc->change(2, 10); // Your container at index 2 will be filled with number 10.
	nc->change(1, 10); // Your container at index 1 will be filled with number 10.
	nc->change(3, 10); // Your container at index 3 will be filled with number 10.
	nc->change(5, 10); // Your container at index 5 will be filled with number 10.
	assert(1 == nc->find(10)); // Number 10 is at the indices 1, 2, 3, and 5. Since the smallest index that is filled with 10 is 1, we return 1.
	nc->change(1, 20); // Your container at index 1 will be filled with number 20. Note that index 1 was filled with 10 and then replaced with 20. 
	assert(2 == nc->find(10)); // Number 10 is at the indices 2, 3, and 5. The smallest index that is filled with 10 is 2. Therefore, we return 2.

	return 0;
}