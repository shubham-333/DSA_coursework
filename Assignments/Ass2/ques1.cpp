#include <iostream>
#include "timer.h"
using namespace std;

bool solve(int *arr, int l, int r, int t) {
	if(l == r) {
		cout<<"No pair found"<<endl;
		return false;
	}
	if(arr[l] + arr[r] == t) {
		cout<<arr[l]<<" "<<arr[r]<<endl;
		return true;
	}
	if(arr[l] + arr[r] >= t)
		return solve(arr, l, r-1, t);

	return solve(arr, l+1, r, t);
}

int main() {

	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

	/*Sample Input
	5               -> size of array
	1 2 3 4 5       -> array elements
	9 -> t
	Sample Output
	4 5
	*/

	Timer timer;
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];
	int t;
	cin >> t;

	timer.start();
	solve(arr, 0, n-1, t);
	timer.stop();

	double milliSecs = timer.getDurationInMilliSeconds();
	cout << "Execution Time: " << milliSecs << " ms." << "\n";

  return 0;
}