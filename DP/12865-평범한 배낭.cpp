#include <iostream>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int N, K;
int dp[101][100001] = {0};
int W[101];
int V[101];

int main()
{
	FastIO;
	cin >> N >> K;
	
	for (int i = 1; i <= N; i++)	{
		int w, v;
		cin >> W[i] >> V[i];
	}

	for (int i = 1; i <= N; i++)	{
		for (int j = 1; j <= K; j++) {
			if (W[i] > j) {
				dp[i][j] = dp[i-1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			}
		}
	}

	cout << dp[N][K];
}
