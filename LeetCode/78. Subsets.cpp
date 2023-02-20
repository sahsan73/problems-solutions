/*
APPROACH: BIT MANIPULATION

COMPLEXITY:
    - TC = O(n*2^n)
    - SC = O(n)
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = (int)nums.size();
        vector<vector<int>> ans;

        for(int i=0; i<(1<<n); ++i) {
            bitset<10> bs(i);
            vector<int> s;
            for(int j=0; j<n; ++j) {
                if(bs[j]) s.push_back(nums[j]);
            }

            ans.push_back(s);
        }

        return ans;
    }
};



/*
APPROACH: BACKTRACKING

COMPLEXITY:
    - TC = O(n*2^n)
    - SC = O(n) // excluding the space occupied for the ans
*/
class Solution {
private:
    void subsets(vector<int> &nums, int i, vector<int> &s, vector<vector<int>> &ans) {
        if(i >= nums.size()) {
            ans.push_back(s);
            return;
        }
        
        // include the element at index i
        s.push_back(nums[i]);
        subsets(nums, i+1, s, ans);
        
        s.pop_back();   // backtrack

        // exclude the element at index
        subsets(nums, i+1, s, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> s;  // subset

        subsets(nums, 0, s, ans);
        return ans;
    }
};
