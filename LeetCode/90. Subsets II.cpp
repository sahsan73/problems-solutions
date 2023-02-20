/*
APPROACH: BACKTRACKING

COMPLEXITY:
    - TC = O(n*2^n)
    - SC = O(n)
*/
class Solution {
private:
    void subsetsWithDup(vector<int> &nums, int i, vector<int> &s, vector<vector<int>> &ans) {
        if(i >= nums.size()) {
            ans.push_back(s);
            return;
        }

        // include the element at index 'i'
        s.push_back(nums[i++]);
        subsetsWithDup(nums, i, s, ans);

        s.pop_back();   // backtrack

        // exclude the element at index 'i' and its duplicate if exists any
        // inorder to avoid duplicate subsets
        while(i<nums.size() && nums[i]==nums[i-1]) i++;
        subsetsWithDup(nums, i, s, ans);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort the input array - it is much more easier to skip
        // duplicate elements in the sort array
        sort(nums.begin(), nums.end());
        
        vector<int> s;
        vector<vector<int>> ans;
        subsetsWithDup(nums, 0, s, ans);
        return ans;
    }
};
