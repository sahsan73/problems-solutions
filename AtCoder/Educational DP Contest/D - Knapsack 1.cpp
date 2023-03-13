#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, W;

int main() {
	cin >> n >> W;
	vector<ll> wt(n), vl(n);
	for(int i=0; i<n; ++i) {
		cin >> wt[i] >> vl[i];
	}

	vector<vector<ll>> dp(n+1, vector<ll>(W+1, 0));
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=W; ++j) {
			ll in=(j>=wt[i-1])?dp[i-1][j-wt[i-1]]+vl[i-1]:0;
			ll ex=dp[i-1][j];
			dp[i][j]=max(in, ex);
		}
	}
	cout << dp[n][W] << '\n';
}
