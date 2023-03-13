/*
Assuming, 1 transaction = sell a stock

APPROACH: DYNAMIC PROGRAMMING
    - Implementation: Bottom-Up (Iteration + Tabulation)

COMPLEXITY:
    - TC = O(kn^2)
    - SC = O(kn)
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int n = (int)p.size();
        vector<vector<int>> dp(k+1, vector<int>(n, 0));

        for(int i=1; i<=k; ++i) {
            for(int j=0; j<n; ++j) {
                // do NOT make the ith (current) transaction
                dp[i][j] = max(dp[i][j], (j>0)?dp[i][j-1]:0);  // NO NEW TRANSACTION ON 0th DAY

                // make the ith transaction
                for(int m=0; m<j; ++m) {
                    dp[i][j] = max(dp[i][j], (p[j]-p[m])+dp[i-1][m]);
                }
            }
        }
        return dp[k][n-1];
    }
};
