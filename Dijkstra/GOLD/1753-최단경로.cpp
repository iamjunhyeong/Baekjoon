#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 20010
#define INF 2147483647
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int v, e, start;
int dist[MAX];
vector<pair<int, int>> graph[MAX];

void solution()
{
	priority_queue<pair<int, int>> PQ;
	PQ.push(make_pair(0, start));
	dist[start] = 0;

	while (!PQ.empty())
	{
		int cost = -PQ.top().first; // 작은 값이 top에 와야하므로 음수화한다.
		int cur = PQ.top().second;
		PQ.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int nCost = graph[cur][i].first;
			int next = graph[cur][i].second;

			if (dist[next] > cost + nCost)
			{
				dist[next] = cost + nCost;
				PQ.push(make_pair(-dist[next], next));
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == INF) cout << "INF" << "\n";
		else cout << dist[i] << "\n";
	}
}

int main()
{
	FastIO;
	cin >> v >> e;
	cin >> start;
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(w, v));
	}
	for (int i = 1; i <= v; i++)  dist[i] = INF;
	solution();
}
