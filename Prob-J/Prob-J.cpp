#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#pragma warning(disable:4996)

typedef struct point {
	int start, end, weight;
} Point;

bool comp(const Point &p1, const Point &p2) {
	if (p1.start == p2.start)
		return p1.end < p2.end;
	return p1.start < p2.start;
}

int main() {
	int n = 0, d = 0, cnt = 0;
    Point* v;

	scanf("%d", &n);
    v = (Point*)malloc(n * sizeof(Point));

	for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v[i].start, &v[i].end);
        v[i].weight = abs(v[i].start - v[i].end);
	}

	sort(v, v + n, comp);

	scanf("%d", &d);

	for (int i = 0; i < n; ++i) {
		int start = v[i].start, end = (int)abs(start + d), temp = 0;
		for (int j = 0; j < n; ++j) {
			if ((d >= v[j].weight) && (start <= v[j].start) && (v[j].end <= end))
				temp++;
			else if (v[j].start > end)
				break;
		}

		cnt = max(cnt, temp);
	}

	printf("%d\n", cnt);
}