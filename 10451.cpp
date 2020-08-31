#include <iostream>
#include <vector>

using namespace std;

bool check[1001];
vector<int> a[1001];


void dfs(int node) {
    if(check[node]) {
        return;
    }
    check[node] = true;
    dfs(a[node].front());
}
int main() {

    int t, n;
    cin >> t;
    int u;
    
    for(int i = 0; i < t; i++) {
        int result = 0;
        cin >> n;
        for(int j = 1; j <=n; j++) {
            a[j].clear();
        }
        for(int j =1; j <= n; j++) {
            cin >> u;
            a[j].push_back(u);
            check[j] = false;
            //a[u].push_back(j);
        }
        for(int j =1; j <=n; j++) {
            if(check[j] == false) {
                dfs(j);
                result = result + 1;     
            }
            
        }
        
        cout << result << '\n';
    }

    
    return 0;
}