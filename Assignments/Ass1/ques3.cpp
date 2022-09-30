#include <iostream>
#include <vector>
using namespace std;

void recursiveBrackets(int n, int leftCount, int rightCount, string s, vector<string>& ans){
	if (leftCount == n && rightCount == n) {
		ans.push_back(s);
		return;
	}

	if (rightCount < n)
		recursiveBrackets(n, leftCount, rightCount + 1, s + "(", ans);

	if (leftCount < rightCount)
		recursiveBrackets(n, leftCount + 1, rightCount, s + ")", ans);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, i;
    cin>>n;
    //cout<<n<<endl;
	vector<string> ans;
    string str = "";
    int leftCount = 0; //count of brackets facing left
    int rightCount = 0; // count of brackets facing right

	recursiveBrackets(n, leftCount, rightCount, str, ans);

	for (i = 0; i<ans.size(); i++)
		cout<<ans[i]<< endl;
    
    return 0;
}
