#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_map; // Stores number -> index
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if the complement already exists in the map
            if (num_map.count(complement)) {
                return {num_map[complement], i};
            }
            
            // Store current number with its index
            num_map[nums[i]] = i;
        }
        
        return {};
    }
};