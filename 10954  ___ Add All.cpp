#include<iostream>
#include<queue>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int n,num,cost,size;
	while (cin >> n&&n){
		priority_queue<int>prio;
		cost = 0;
		for (int i = 0; i < n; i++){
			cin >> num;
			prio.push(-num);
		}
		size = prio.size();
		for (int i = 0; i < size-1; i++){
			int Top1 = -prio.top();
			prio.pop();
			int Top2 = -prio.top();
			prio.pop();
			cost += (Top1 + Top2);
			prio.push(-(Top1 + Top2));
		}
		cout << cost << endl;
	}
	return 0;
}
