/*
APPROACH: GREEDY

COMPLEXITY:
    - TC = O(n)
    - SC = O(1)
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0, r=0;   // current window boundary
        int cnt = 0;
        while(r < nums.size()-1) {
            ++cnt;

            int farthest = -1;
            for(int i=l; i<=r; ++i) {
                farthest = max(farthest, i+nums[i]);
            }

            l = r+1;
            r = farthest;
        }

        return cnt;
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING
    - Implementation: Bottom-up (Iteration + Tabulation)
    
COMPLEXITY:
    - TC = O(n^2)
    - SC = O(n)
*/
class Solution {
private:
    const int INF = 1e9;

public:
    int jump(vector<int>& nums) {
        int n = (int)nums.size();

        vector<int> dp(n, INF);
        dp[n-1] = 0;
        for(int i=n-2; ~i; --i) {
            for(int j=1; j<=nums[i]; ++j) {
                if(i+j >= n) break;
                dp[i] = min(dp[i], 1+dp[i+j]);
            }
        }
        return dp[0];
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING
    - Implementation: Top Down (Recursion + Memoization)
    
COMPLEXITY:
    - TC = O(n^2)
    - SC = O(n)
*/
class Solution {
private:
    const int INF = 1e9;
    int n;

    int dfs(vector<int> &nums, int i, int n, vector<int> &dp) {
        if(i == n-1) return 0;
        if(dp[i] != INF) return dp[i];

        for(int j=1; j<=nums[i]; ++j) {
            if(i+j >= n) break;
            dp[i] = min(dp[i], 1+dfs(nums, i+j, n, dp));
        }
        return dp[i];
    }

public:
    int jump(vector<int>& nums) {
        n = (int)nums.size();
        vector<int> dp(n, INF);
        dp[n-1] = 0;

        return dfs(nums, 0, n, dp);
    }
};
