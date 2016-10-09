#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#pragma warning(disable:4996)

typedef struct point {
	int start, end;
} Point;

bool comp(const Point &p1, const Point &p2) {
	if (p1.end == p2.end) {
		return p1.start < p2.start;
	}
	return p1.end < p2.end;
}

int main() {
	int n = 0, d = 0, cnt = 0;
	priority_queue<int> q;
    Point* v;

	scanf("%d", &n);
    v = (Point*)malloc(n * sizeof(Point));

	for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v[i].start, &v[i].end);
        if (v[i].start > v[i].end)
            swap(v[i].start, v[i].end);
	}

	sort(v, v + n, comp);

	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", v[i].start, v[i].end);
	}

	scanf("%d", &d);

	for (int i = 0; i < n; ++i) {
		q.push(-v[i].start);
		while (!q.empty() && -q.top() < v[i].end - d)
			q.pop();
		cnt = max(cnt, (int) q.size());
	}

	printf("%d\n", cnt);
}