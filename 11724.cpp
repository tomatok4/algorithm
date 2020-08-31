#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool check[1001];
vector<int> a[1001];

void bfs(int i) {
    queue<int> q;
    check[i] = true;
    q.push(i);
    
    while(!q.empty()) {
        int n = q.front();
        q.pop();
        for(int i = 0; i < a[n].size(); i++) {
            int m = a[n][i];
            if(check[m] == false) {
                check[m] = true;
                q.push(m);
            }
        }   
    }
}

void dfs(int node) {
    check[node] = true;
    for (int i=0; i<a[node].size(); i++) {
        int next = a[node][i];
        if (check[next] == false) {
            dfs(next);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    int link = 0;
    for(int i = 1; i <= n ; i ++) {
        if(check[i] == false) {
            //bfs(i);
            dfs(i);
            link++;
        }
    }

    cout << link << '\n';
    return 0;
}