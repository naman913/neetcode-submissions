#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Max-heap initialized with the vector elements
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

            if (first != second) {
                pq.push(first - second);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};