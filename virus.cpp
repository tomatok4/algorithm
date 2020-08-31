#include <iostream>
#include <queue>
using namespace std;
int com[101][101];
int number;
int p;
int to, from;
int visit[101];
queue <int> q;
int c;

void bfs() {
    q.push(1);
    visit[1] = 1;
    c = 0;
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        for( int i = 1; i <= 100; ++i) {
            if(com[current][i] && !visit[i]) {
                visit[i] = 1;
                q.push(i);
                //cout << current << " -> " << i << endl;
                c++;
            }
        }
    }
}
int main() {
    cin >> number >> p;
    for(int i = 1; i <= p; i++) {
        cin >> to >> from;
        com[to][from] = 1;
        com[from][to] = 1;
    }
    bfs();

    //printf("%d\n", q.back());
    cout << c << endl;

    return 0;
}