#include <iostream>
#include <vector>
using namespace std;

void sort_(vector<int> a, int size) {
	for (int j = 1; j < size; j++) {
		int key = a[j];
		int i = j - 1;
		while (i > -1 && a[i] > key) {
			a[i + 1] = a[i];
			i = i - 1;
		}
		a[i + 1] = key;
	}
}

int main(){

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    int N, K, i, sum = 0;
    cin >> N >> K;
    vector<int> a(N, 0);

    for(int i=0; i<N; i++)
        cin >> a[i];

    sort_(a, N);

    for(i=0; i<N; i++){
        sum += a[i];
        if(sum > K){
            break;
        }
    }
    cout<<i+1<<endl;
    return 0;
}
