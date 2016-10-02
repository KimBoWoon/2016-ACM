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

vector<Point> v;

int main() {
	int n = 0, d = 0, cnt = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		int start, end;
		scanf("%d %d", &start, &end);
		if (start > end)
			v.push_back({ end, start, (int)abs(start - end) });
		else
			v.push_back({ start, end, (int)abs(start - end) });
	}

	sort(v.begin(), v.end(), comp);

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