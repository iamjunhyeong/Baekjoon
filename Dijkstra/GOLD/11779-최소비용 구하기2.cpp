#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 1010
#define INF 2147483647
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;


int n, m, start, ari;
int route[MAX];
int dist[MAX];
vector<int> route_v;
vector<pair<int, int>> graph[MAX];

void Solve()
{
	priority_queue<pair<int, int>> PQ;
	PQ.push(make_pair(0, start));
	dist[start] = 0;
	
	while (!PQ.empty())
	{
		int cost = -PQ.top().first;
		int cur = PQ.top().second;
		PQ.pop();

		if (cost > dist[cur])
			continue;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int nCost = graph[cur][i].second;

			if (dist[next] > nCost + cost)
			{
				route[next] = cur;
				dist[next] = nCost + cost;
				PQ.push(make_pair(-dist[next], next));
			}
		}
	}
	
	cout << dist[ari] << "\n";
	int tmp = ari;
	while (tmp)
	{
		route_v.push_back(tmp);
		tmp = route[tmp];
	}
	cout << route_v.size() << "\n";
	for (int i = route_v.size() - 1; i >= 0; i--) cout << route_v[i] << " ";
	cout << "\n";
}

int main()
{
	FastIO;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e, w; cin >> s >> e >> w;
		graph[s].push_back(make_pair(e, w));
	}
	for (int i = 0; i < n + 1; i++) dist[i] = INF;

	cin >> start >> ari;
	Solve();
}