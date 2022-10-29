#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkSort(int n, queue<int> q) {
	stack<int> s;
	int res = 1;
	int frontElement;

	while(!q.empty()) {
		frontElement = q.front();
		q.pop();

		if(frontElement == res) {
			res++;
		}
		else {
			if(s.empty()) 
				s.push(frontElement);
			else if(!s.empty() && s.top() < frontElement) 
				return false;
			else
				s.push(frontElement);
		}
	}

	while(!s.empty() && s.top() == res) {
		s.pop();
		res++;
	}

	if(res == n + 1 && s.empty()) 
		return true;

	return false;
}

int main() {

    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		queue<int> q;
		int x;

		for(int i = 0; i < n; i++) {
			cin >> x;
			q.push(x);
		}
		
		if(checkSort(n, q))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	
}