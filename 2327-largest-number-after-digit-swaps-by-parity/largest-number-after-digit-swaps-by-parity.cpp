#include <string>
#include <queue>
#include <iostream>

class Solution {
public:
    int largestInteger(int num) {
        std::priority_queue<int> pq1; // Even digits priority queue
        std::priority_queue<int> pq2; // Odd digits priority queue
        
        std::string N = std::to_string(num);
        
        // Step 1: Separate even and odd digits into respective priority queues
        for (int i = 0; i < N.size(); i++) {
            int d = N[i] - '0';
            if (d % 2 == 0) {
                pq1.push(d);
            } else {
                pq2.push(d);
            }
        }
        
        std::string res = "";
        
        // Step 2: Reconstruct the number by picking the largest available parity digits
        for (int i = 0; i < N.size(); i++) {
            int d = N[i] - '0';
            if (d % 2 == 0) {
                res += std::to_string(pq1.top());
                pq1.pop();
            } else {
                res += std::to_string(pq2.top());
                pq2.pop();
            }
        }
        
        return std::stoi(res);
    }
};