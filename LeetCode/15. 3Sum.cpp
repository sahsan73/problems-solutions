class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();

        vector<vector<int>> ans;
        for(int i=0; i<n-2; ++i) {
            // remove duplicate triplet
            if(i && nums[i]==nums[i-1]) continue;

            int j=i+1, k=n-1;
            while(j<k) {
                // remove duplicate pair
                if(j>i+1 && nums[j]==nums[j-1]) {
                    ++j;
                    continue;
                }

                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    ans.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                } else if(sum > 0) {
                    --k;
                } else {
                    ++j;
                }
            }
        }

        return ans;
    }
};
