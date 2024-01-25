#include <iostream>
#include <vector>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int main()
{
	FastIO;
	int n, m;

	cin >> n >> m;
	vector<int> arr;
	for (int i = 0; i < n; i++)
		arr.push_back(i + 1);

	while (m--)
	{
		int a, b; cin >> a >> b;
		a--; b--;
		int tmp;
		tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}
	for (int i : arr)
		printf("%d ", i);
	return 0;
}