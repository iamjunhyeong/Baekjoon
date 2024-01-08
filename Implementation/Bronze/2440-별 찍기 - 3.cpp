#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int main()
{
	int n, m; cin >> n;
	m = n;
	for (int i = 0; i < m; i++) {
		for (int j = n; j > 0; j--) 
			printf("*");
		printf("\n");
		n--;
	}
}
