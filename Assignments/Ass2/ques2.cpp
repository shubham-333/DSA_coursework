#include <iostream>
#include <deque>
using namespace std;

void solve(int *arr, int n, int k) {
	deque<int> q(k);
	int i;

	for(i=0; i<k; i++) {
		while(!q.empty() && arr[i] >= arr[q.back()])
			q.pop_back();
		q.push_back(i);
	}

	for(int j=i; j<n; j++) {
		cout << arr[q.front()] << " ";
        
		while(!q.empty() && q.front() <= j-k)
			q.pop_front();

		while(!q.empty() && arr[j] >= arr[q.back()])
			q.pop_back();

		q.push_back(j);
	}
	cout << arr[q.front()] << endl;
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		solve(arr, n, k);
	}
}