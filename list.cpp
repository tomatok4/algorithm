#include <iostream>
#include <vector>

using namespace std;

vector <pair<int, int>> a[10];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i =0; i <m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        a[u].push_back(make_pair(v,w));
        a[v].push_back(make_pair(u,w));
    }
}

