class Solution {
public:
int dp[3000][3001];
int solve(vector<int> &nums,int prev,int i){
    if(i >= nums.size())return 0;
    if(dp[i][prev+1] != -1)return dp[i][prev+1];
    int notTake = solve(nums,prev,i+1);
    int take=0;
    if(prev == -1 || nums[prev] < nums[i]){
        take = 1 + solve(nums, i, i+1);
    }
    return dp[i][prev+1]=max(take,notTake);
}
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums,-1,0);
    }
};