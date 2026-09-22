#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumScore(std::vector<int>& nums, int k) {
        int i = k, j = k;
        int minVal = nums[k];
        int maxScore = minVal;
        int n = nums.size();
        
        while (i > 0 || j < n - 1) {
            if (i == 0) {
                j++;
            } else if (j == n - 1) {
                i--;
            } else if (nums[i - 1] < nums[j + 1]) {
                j++;
            } else {
                i--;
            }
            
            minVal = std::min({minVal, nums[i], nums[j]});
            maxScore = std::max(maxScore, minVal * (j - i + 1));
        }
        
        return maxScore;
    }
};