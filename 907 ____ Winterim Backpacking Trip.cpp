#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int n, k,num,sum;
	cin >> n >> k;
	vector<int>vec;
	priority_queue<int> q,sec;
	for (int i = 0; i < n + 1; i++){
		cin >> num;
		vec.push_back(num);
		sec.push(num);
	}
	int diff = n - k;
	for (int i = 0; i < vec.size() - diff;i++){
		sum = 0;
		for (int j = i; j <= i+diff; j++){
			sum += vec[j];
		}
		q.push(-sum);
	}
	int check = -q.top();
	if (check >= sec.top())
		cout << sec.top();
	else
		cout << check;
	cout << endl;
}