/*
SAME CONCEPT AS: "188. Best Time to Buy and Sell Stock IV"
    - My Sol: 
    
    - For this problem, set k = 2

APPROACH: DYNAMIC PROGRAMMING
    - Implementation: Bottom-Up (Iteration + Tabulation)
    
COMPLEXITY:
    - TC = O(n)
    - SC = O(n)
*/



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING
    - Precalculate the transaction profit from left side (for first transaction)
      and from the right side (for second transaction)

COMPLEXITY:
    - TC = O(n)
    - SC = O(n)
*/
class Solution {
public:
    int maxProfit(vector<int> &p) {
        int n = (int)p.size();

        // first transaction: maximum profit if we sell a stock on ith day
        vector<int> ftp(n, 0);
        int mn = p[0];
        for(int i=1; i<n; ++i) {
            ftp[i] = max(ftp[i-1], p[i]-mn);
            mn = min(mn, p[i]);
        }

        // second transaction: maximum profit if we buy a stock on jth day
        vector<int> stp(n, 0);
        int mx = p[n-1];
        for(int j=n-2; ~j; --j) {
            stp[j] = max(stp[j+1], mx-p[j]);
            mx = max(mx, p[j]);
        }

        int ans = 0;
        for(int i=0; i<n; ++i) {
            ans = max(ans, ftp[i]+stp[i]);
        }
        return ans;
    }
};



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: BRUTE FORCE
    - Using the concept of, "121. Best Time to Buy and Sell Stock"
    - My Sol: https://github.com/sahsan73/problems-solutions/blob/main/LeetCode/Best%20Time%20to%20Buy%20and%20Sell%20Stock/121.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock.cpp

                        first trans     // second trans
    - Two transactions = [0,...,i)   +   [i....n)

COMPLEXITY:
    - TC = O(n^2)
    - SC = O(1)
    
VERDICT: TLE
*/
class Solution {
private:
    int singleTransaction(int lo, int hi, vector<int> &p) {
        int ans=0, mn=p[lo];
        for(int i=lo; i<hi; ++i) {
            ans = max(ans, p[i]-mn);
            mn = min(mn, p[i]);
        }
        return ans;
    }

public:
    int maxProfit(vector<int> &p) {
        int n = (int)p.size();
        int ans = 0;
        for(int i=0; i<n; ++i) {
            // first transaction profit (ftp)
            int ftp = singleTransaction(0, i, p);
            // second transaction profit (stp)
            int stp = singleTransaction(i, n, p);

            ans = max(ans, ftp+stp);
        }
        return ans;
    }
};
