#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int n;
	int* arr;

	scanf("%d", &n);

	arr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + n, greater<int>());

	for (int i = n; i; i--) {
		if (arr[i] >= i) {
			printf("%d\n", i + 1);
			return 0;
		}
	}
	printf("0\n");
}