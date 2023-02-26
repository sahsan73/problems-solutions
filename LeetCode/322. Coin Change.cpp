/*
APPROACH: DYNAMIC PROGRAMMING
    - Implementation: Bottom Up
    - An application of Unbounded Knapsack Problem
    
COMPLEXITY:
    - TC = O(amt*n)
    - SC = O(amt)
*/
class Solution {
private:
    const int INF = 1e9;

public:
    int coinChange(vector<int>& coins, int amt) {
        vector<int> dp(amt+1, INF);
        dp[0] = 0;

        for(int j=1; j<=amt; ++j) {
            for(int i=0; i<(int)coins.size(); ++i) {
                if(j<coins[i]) continue;
                dp[j] = min(dp[j], 1+dp[j-coins[i]]);
            }
        }

        return (dp[amt]==INF)?-1:dp[amt];
    }
};
