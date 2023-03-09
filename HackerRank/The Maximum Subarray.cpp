/*
PROBLEM STATEMENT: https://www.hackerrank.com/challenges/maxsubarray/problem?isFullScreen=true

APPROACH: KADANE'S ALGORITHM

COMPLEXITY:
    - TC = O(n)
    - SC = O(1)
*/
vector<int> maxSubarray(vector<int> arr) {
    int n = (int)arr.size();
    
    // max sum in subarray - Kadane's Algorithm
    int s1=arr[0], tmp=arr[0];
    for(int i=1; i<n; ++i) {
        tmp = max(arr[i], tmp+arr[i]);
        s1 = max(s1, tmp);
    }
    
    // max sum in subsequence
    int mx = INT_MIN, s2 = 0;
    for(int i=0; i<n; ++i) {
        mx = max(mx, arr[i]);
        if(arr[i]>0) s2 += arr[i];
    }
    s2 = (s2==0) ? mx : s2;
    
    return vector<int>{s1, s2};
}
