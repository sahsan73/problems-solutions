#include <bits/stdc++.h>
using namespace std;

int n;
const int mxN=3;

int main() {
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(mxN));
	for(int i=0; i<n; ++i) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	vector<vector<int>> dp(n, vector<int>(mxN, 0));
	dp[0][0]=arr[0][0], dp[0][1]=arr[0][1], dp[0][2]=arr[0][2];
	for(int i=1; i<n; ++i) {
		for(int j=0; j<mxN; ++j) {
			for(int k=0; k<mxN; ++k) {
				if(k==j) continue;
				dp[i][j]=max(dp[i][j], dp[i-1][k]);
			}
			dp[i][j]+=arr[i][j];
		}
	}

	cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << '\n';
}
