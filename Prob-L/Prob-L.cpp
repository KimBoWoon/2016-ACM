#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int n, w, l;
	vector<int> v(1001);

	scanf("%d %d %d", &n, &w, &l);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	int ans = 0, weight = 0, cnt = 0;
	for (int i = 0; i < n; i += cnt) {
		cnt = 0;
		for (int j = i; j < n; ++j) {
			weight += v[j];
			cnt++;
			if (weight + v[j + 1] > l)
				break;
		}

		ans += w;
		weight = 0;
	}

	printf("%d\n", ans);
}