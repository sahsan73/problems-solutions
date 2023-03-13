class Solution {
public:
    int maxProfit(vector<int> &p) {
        int ans=0, mn=p[0];
        for(int i=1; i<p.size(); ++i) {
            ans = max(ans, p[i]-mn);
            mn = min(mn, p[i]);
        }
        return ans;
    }
};
