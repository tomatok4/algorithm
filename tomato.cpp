#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int m, n;
//int map[1001][1001];
//int visited[1001][1001];

queue <pair<int, int>> q;
int day;
int temp;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(vector<vector<int>>& map, vector<vector<int>>& visited) {
    while(true) {
        queue<pair<int, int>> q2;
        while(!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int dir=0; dir <4; dir++) {
                int ny= y + dy[dir];
                int nx = x + dx[dir];

                if(ny<0 || ny>=n || nx<0 || nx>=m) {
                    continue;
                }
                if(visited[ny][nx] || map[ny][nx] != 0) {
                    continue;
                }

                visited[ny][nx]++;
                map[ny][nx]=1;
                q2.push(make_pair(ny,nx));
            }
        }

        q = q2;
        if(q.empty()) {
            break;
        }
        day++;
    }

    for(int i=0;i<n;i++) {
        for(int j=0; j<m;j++) {
            if(map[i][j]==0) {
                day = -1;
                break;
            }
        }
    }

}
int main(void) {

    cin >> m >> n;
    vector<vector<int>> map(n, vector<int>(m,0));
    vector<vector<int>> visited(n, vector<int>(m,0));


    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            cin >> map[i][j];
            if(map[i][j]==1){
                q.push(make_pair(i,j));
                visited[i][j]++;
            }
        }
    }
    if(q.size()==m*n) {
        cout<<0<<'\n';
        return 0;
    }
    bfs(map, visited);
    cout << day << '\n';

    return 0;
}