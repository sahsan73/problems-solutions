/*
        Sj - Si = k
    ==> Sj - k = Si

    // Store the values of Si
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> Si;
        Si[0] = 1;

        int cnt=0, Sj=0;
        for(int i=0; i<nums.size(); ++i) {
            Sj += nums[i];
            cnt += Si[Sj-k];

            ++Si[Sj];
        }
        return cnt;
    }
};
