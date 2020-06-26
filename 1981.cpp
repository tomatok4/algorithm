#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int t;
int c[101][101];
bool visit[101][101];
vector<int> max_v;
vector<int> min_v;
int diff;
queue <int> qx;
queue <int> qy;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs() {
    visit[1][1] = true;
    qx.push(1);
    qy.push(1);
    max_v.push_back(c[1][1]);
    min_v.push_back(c[1][1]);
    diff = 0;
    
    int temp_x, temp_y;
    while(!qx.empty() && !qy.empty()) {
        temp_x = qx.front();
        qx.pop();
        temp_y = qy.front();
        qy.pop();
        for(int i = 0; i < 4; i++) {
            int xx = temp_x + dx[i];
            int yy = temp_y + dy[i];
            
            if(xx>0 && xx<=t && yy>0 && yy<=t && !visit[xx][yy]) {
                visit[xx][yy] = true;
                qx.push(xx);
                qy.push(yy);
                
                if(max_v[max_v.size()-1] < c[xx][yy])
                    max_v.push_back(c[xx][yy]);

                if(min_v [min_v.size()-1]> c[xx][yy])
                    min_v.push_back(c[xx][yy]);
                
                if(diff > max_v.back() - min_v.back()) {
                    diff = max_v.back() - min_v.back();
                }
                
            }
            
        }
    }
    
    return diff;
}

int main(void) {

    int result;
    cin >> t;
    for(int i = 1; i<=t; i++) {
        for(int j = 1; j<=t; j++) {
            cin >> c[i][j];
        }
    }


    result = bfs();
    cout << result << '\n';

    return 0;
}