class Solution {
private:
    bool findSubset(vector<int> &nums, int s) {
        int n = (int)nums.size();
        vector<vector<bool>> dp(n+1, vector<bool>(s+1, 0));
        for(int i=0; i<=n; ++i) dp[i][0]=1;

        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=s; ++j) {
                bool in = (j<nums[i-1]) ? 0 : dp[i-1][j-nums[i-1]];
                bool ex = dp[i-1][j];
                dp[i][j] = in||ex;
            }
        }
        return dp[n][s];
    }

public:
    bool canPartition(vector<int>& nums) {
        int s = std::accumulate(nums.begin(), nums.end(), 0);
        if(s&1) return false;

        // find the subset with sum = s/2
        return findSubset(nums, s/2);
    }
};
