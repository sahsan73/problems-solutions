class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();

        int ans = -1, diff = 1e9+5;
        for(int i=0; i<n-2; i++) {
            if(i && nums[i]==nums[i-1]) continue;

            int j=i+1, k=n-1;
            while(j < k) {
                if(j>i+1 && nums[j]==nums[j-1]) {
                    ++j;
                    continue;
                }

                int s = nums[i]+nums[j]+nums[k];
                if(s == target) return target;
                int currDiff = abs(target - s);
                if(diff > currDiff) {
                    ans = s;
                    diff = currDiff;
                }

                if(s > target) --k;
                else ++j;
            }
        }

        return ans;
    }
};
