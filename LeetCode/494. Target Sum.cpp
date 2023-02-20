/*
APPROACH: DYNAMIC PROGRAMMING

COMPLEXITY:
    - TC = O(n*t)
    - SC = O(n*t)


Note: In this case, we CANNOT use matrix to memoize the result since
      sum value (t) can be NEGATIVE!!
*/
typedef pair<int, int> pii;
#define mp make_pair

class Solution {
private:
    int findTargetSumWays(vector<int> &nums, int i, int t, map<pii,int> &dp) {
        if(i >= nums.size()) return t==0;
        if(dp.count(mp(i, t))) return dp[mp(i,t)];

        int add = findTargetSumWays(nums, i+1, t-nums[i], dp);
        int sub = findTargetSumWays(nums, i+1, t+nums[i], dp);

        return dp[mp(i,t)] = add + sub;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pii, int> dp;
        return findTargetSumWays(nums, 0, target, dp);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: BACKTRACKING

COMPLEXITY:
    - TC = O(2^n)
    - SC = O(1)
*/
class Solution {
private:
    int findTargetSumWays(vector<int> &nums, int i, int t) {
        if(i >= nums.size()) return t==0;

        int add = findTargetSumWays(nums, i+1, t-nums[i]);
        int sub = findTargetSumWays(nums, i+1, t+nums[i]);

        return add + sub;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return findTargetSumWays(nums, 0, target);
    }
};
