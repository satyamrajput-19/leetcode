class Solution {
public:
int dp[10001];

int solve(vector<int>& nums,int ind){
    if(ind >= nums.size() - 1)return 0;

    if (dp[ind] != -1) return dp[ind];

    int res = 10000;

    for(int i = ind + 1; i <= min((int)nums.size() -1, ind + nums[ind]);i++){
        int temp = 1 + solve(nums, i);
        res = min(res, temp);
    }
    return dp[ind] = res;
}
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);    
    }
};