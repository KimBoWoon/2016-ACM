#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

#pragma warning(disable:4996)

int arr[1001];

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	sort(arr + 1, arr + n + 1, greater<int>());

	for (int i = n; i; i--) {
		if (arr[i] >= i) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("0\n");
}