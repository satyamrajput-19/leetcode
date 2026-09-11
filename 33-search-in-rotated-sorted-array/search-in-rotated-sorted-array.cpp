class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = nums.size();
        if (nums[0] < nums[s - 1]) 
            return 0;
            
        int l = 0, r = s - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[s - 1]) 
                l = m + 1;
            else 
                r = m;
        }
        return l; 
    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int tar) {
        int i = findMin(nums);
        int l = binarySearch(nums, tar, 0, i - 1);
        int r = binarySearch(nums, tar, i, nums.size() - 1);
        return max(l, r);
    }
};