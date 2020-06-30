#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
//최소신장트리(mst) 문제
int check[100];
bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}
int getParent(int node){
	if(check[node]==node) return node;
	return getParent(check[node]);
}

//두 노드를 작은값을 기준으로 연결합니다. 
void unionParent(int node1, int node2){
	node1 = getParent(node1);
	node2 = getParent(node2);
	if(node1<node2) check[node2] = node1;
	else check[node1] = node2;
}

//싸이클이 존재하면 true, 아니면 false를 반환
bool isCycle(int node1, int node2){
	node1 = getParent(node1);
	node2 = getParent(node2);
	if(node1==node2) return true;
	else return false;
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), compare);
    for(int i = 0; i < n; i++) {
        check[i] = i;
    }
    
	for(int i=0;i<costs.size();++i){
		//싸이클이 존재하지 않으면 비용을 더합니다. 
		if(!isCycle(costs[i][0], costs[i][1])){
			answer+=costs[i][2];
			unionParent(costs[i][0], costs[i][1]);
		}
	}
    
    return answer;
}