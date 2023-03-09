/*
numTrees(n) = {numTrees(0) * numTrees(n-1)}  +
              {numTrees(1) * numTrees(n-2)}  +
              {numTrees(2) * numTrees(n-3)}  +
              ...
              ...
              ...
              {numTrees(n-2) * numTrees(1)}  +
              {numTrees(n-1) * numTrees(0)}

*/

/*
APPROACH: DYNAMIC PROGRAMMING
    - Implementation: Bottom-Up (Iteration + Tabulation)

COMPLEXITY:
    - TC = O(n^2)
    - SC = O(n)
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;

        for(int i=2; i<=n; ++i) {
            int j=0, k=i-1;
            while(j < k) {
                dp[i] += 2*dp[j]*dp[k]; // (optimization: numTrees(0)*numTrees(n-1) == numTrees(n-1)*numTrees(0)
                ++j, --k;
            }

            if(i&1) dp[i] += dp[i/2]*dp[i/2];
        }

        return dp[n];
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING
    - Implementation: Top-Down (Recursion + Memoization)

COMPLEXITY:
    - TC = O(n^2)
    - SC = O(n)
*/
class Solution {
private:
    int numTrees(int n, vector<int> &dp) {
        if(n <= 1) return 1;
        if(dp[n] != 0) return dp[n];

        int res = 0;
        for(int j=1; j<=n; ++j) {
            res += numTrees(j-1, dp) * numTrees(n-j, dp);
        }
        return dp[n] = res;
    }

public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        return numTrees(n, dp);
    }
};
