#include <iostream>
#include <queue>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

priority_queue<int> pq;
int n;
int main(void)
{
	FastIO;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;

		if (x == 0)
		{
			if (pq.empty())
			{
				cout << "0" << "\n";
				continue;
			}
			int top;
			cout << pq.top() * (-1) << "\n";
			pq.pop();
		}
		else
			pq.push(-x);
	}
}