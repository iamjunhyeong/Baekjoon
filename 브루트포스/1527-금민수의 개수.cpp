#include <iostream>
#include <queue>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m; 

int sol()
{
	int cnt = 0;
	int depth = 0;

	queue<int> qu;
	qu.push(4);
	qu.push(7);
	
	while (!qu.empty())
	{
		int a = qu.front();
		qu.pop();

		if (m < a) continue;
		if (n <= a)	cnt++;
		if (a >= 444444444) continue;
		qu.push(a * 10 + 4);
		qu.push(a * 10 + 7);
	}
	return cnt;
}

int main()
{
	FastIO;
	cin >> n >> m;
	cout << sol() << "\n";
}

