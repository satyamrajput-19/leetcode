class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=nums.size();
        //if array is sorted
        if (nums[0] < nums[s-1])
            return nums[0];
        int l = 0,r=s-1;
        while(l < r){
            int m = l + (r - l) / 2;
            //describe left or right side
            if (nums[m] > nums[s-1])
                l=m+1;
            else
                r=m;
        }
        return nums[l];
    }
};