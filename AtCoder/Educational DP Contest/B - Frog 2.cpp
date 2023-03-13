/*
COMPLEXITY:
    - TC = O(n*k)
    - SC = O(n)
*/
#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0; i<n; ++i) cin >> arr[i];

	vector<int> dp(n, 1e9+5);
	dp[0]=0;
	for(int i=1; i<n; ++i) {
		for(int j=1; j<=k&&i-j>=0; ++j) {
			dp[i]=min(dp[i], dp[i-j]+abs(arr[i]-arr[i-j]));
		}
	}
	cout << dp[n-1] << '\n';
}
