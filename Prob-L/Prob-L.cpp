#include <cstdlib>
#include <cstdio>
#include <queue>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int n, w, l;
	queue<int> q;

	scanf("%d %d %d", &n, &w, &l);

	int ans = 0, cnt = 0, sum = 0;
	for (int i = 0; i < n; ++i) {
		int weight = 0;

		scanf("%d", &weight);
		for ( ; ; ) {
			ans++;
			if (cnt == w) {
				cnt--;
				sum -= q.front();
				q.pop();
			}
			if (sum + weight > l) {
				cnt++;
				q.push(0);
			}
			else {
				cnt++;
				q.push(weight);
				sum += weight;
				break;
			}
		}
	}

	printf("%d\n", ans + w);
}