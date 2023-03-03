/*
Problem Statement: https://www.hackerrank.com/challenges/the-power-sum/problem

APPROACH: BACKTRACKING

COMPLEXITY:
    - TC = O(2^(pow(X, 1.0/N)))
    - SC = O(1)
*/
int dfs(int i, int lim, int X, int N) {
    if(X == 0) return 1;
    if(i>lim || X<0) return 0;
    
    int include = dfs(i+1, lim, X-pow(i,N), N);
    int exclude = dfs(i+1, lim, X, N);
    
    return include + exclude;
}

int powerSum(int X, int N) {
    int lim = pow(X, 1.0/N);
    return dfs(1, lim, X, N);
}
