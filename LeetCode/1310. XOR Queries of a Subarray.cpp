/*
APPROACH: PREFIX SUM
    - Pre computation of the range xor of values
    - pxor[i] = arr[0]^arr[1]^....^arr[i]
    
    - Intuition: X^Y = Z   ==> Y = X^Z

COMPLEXITY:
    TC = O(n)
    SC = O(q)   // considering the space for storing queries ans
    
VERDICT: AC
*/
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pxor{arr[0]};   // prefix xor
        for(int i=1; i<arr.size(); ++i) pxor.push_back(pxor[i-1]^arr[i]);

        vector<int> ans;
        for(auto &q: queries) {
            int l = (q[0]==0) ? 0 : pxor[q[0]-1];
            int r = pxor[q[1]];

            ans.push_back(r^l);
        }
        return ans;
    }
};



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: SEGMENT TREE
    - ...

COMPLEXITY:
    TC = O(q*logn), where q = number of queries
    
VERDICT: AC
*/
class SegTree {
private:
    int n;  // size of the actual input array
    vector<int> ST;
public:
    SegTree(vector<int> &arr) {
        this->n = (int)arr.size();
        ST.resize(4*n, 0);
        this->build(0, n-1, 0, arr);
    }

    void build(int i, int j, int curr, vector<int> &arr) {
        if(i==j) {  // leaf node
            ST[curr] = arr[i];
            return;
        }

        int m = (i + j)/2;
        build(i, m, 2*curr+1, arr);     // build left child
        build(m+1, j, 2*curr+2, arr);   // build right child

        ST[curr] = ST[2*curr+1]^ST[2*curr+2];
    }

    int query(int i, int j, int l, int r, int curr) {
        // no overlap
        if(i>r || j<l) return 0;
        // complete overlap
        if(i>=l && j<=r) return ST[curr];

        int m = (i + j) / 2;
        int left_query = query(i, m, l, r, 2*curr+1);
        int right_query = query(m+1, j, l, r, 2*curr+2);
        return left_query^right_query;
    }
    int query(int l, int r) {
        return query(0, n-1, l, r, 0);
    }
};

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        SegTree t(arr);
        
        vector<int> ans;
        for(auto &q: queries) ans.push_back(t.query(q[0], q[1]));
        return ans;
    }
};
