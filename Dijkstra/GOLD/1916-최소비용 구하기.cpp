#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100001
#define INF 2147483647
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m, dep, ari;
int dist[MAX];
vector<pair<int, int>> graph[MAX];

void Solve()
{
	priority_queue<pair<int, int>> PQ;
	PQ.push(make_pair(0, dep));
	dist[dep] = 0;

	while (!PQ.empty())
	{
		int cost = -PQ.top().first;
		int cur = PQ.top().second;
		PQ.pop();

		if (dist[cur] < cost) continue;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int nCost = graph[cur][i].first;
			int next = graph[cur][i].second;

			if (dist[next] > nCost + cost)
			{
				dist[next] = nCost + cost;
				PQ.push(make_pair(-dist[next], next));
			}

		}
	}
	if (dist[ari] == INF) cout << "INF" << "\n";
	else cout << dist[ari] << "\n";
}

int main()
{
	FastIO;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e, w; cin >> s >> e >> w;
		graph[s].push_back(make_pair(w, e));
	}
	for (int i = 1; i < n + 1; i++) dist[i] = INF;

	cin >> dep >> ari;
	Solve();
}