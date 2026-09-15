#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4) return ans;

        // 1. Sort array to use two-pointer method and avoid duplicates easily
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Use long long to avoid integer overflow during summation
                long long newTarget = (long long)target - nums[i] - nums[j];
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = nums[left] + nums[right];

                    if (sum == newTarget) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates for the third and fourth elements
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    } else if (sum < newTarget) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};