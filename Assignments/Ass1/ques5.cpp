#include <iostream>
using namespace std;

void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

int main() {
	
	// #ifndef ONLINE_JUDGE
	// 		freopen("input.txt", "r", stdin);
	// 		freopen("output.txt", "w", stdout);
	// #endif

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int maxId;
	int count = 0;

	for (int i = 0; i < n - 1; i++) {
		maxId = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] > arr[maxId]) {
				maxId = j;
			}
		}
		if (maxId != i) {
			swap(arr[i], arr[maxId]);
			count++;
		}
	}

	cout << count;
	return 0;
}