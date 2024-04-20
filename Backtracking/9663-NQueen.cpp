#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;


int n, cnt = 0;

int find_queen(vector<int> &b, int dep, int ind)
{
	for (int i = 0; i < dep; i++) 
	{
		if (b[i] == ind) return 1;
		double x = (double)ind - b[i];
		double y = (double)dep - i;
		if (x / y == 1 || x / y == -1) return 1;
	}
	return 0;
}

void dfs(int dep, vector<int> &b) 
{
	if (dep == n) 
	{
		cnt++;
		return ;
	}
	for (int i = 0; i < n; i++) {
		if (!find_queen(b, dep, i)) {
			b[dep] = i;
			dfs(dep + 1, b);
		}
	}
	return ;
}

int main() 
{
	FastIO;
	cin >> n;
	vector<int> b(n);

	fill(b.begin(), b.end(), 0);
	if (n != 0)
		dfs(0, b);
	cout << cnt << "\n";
}
