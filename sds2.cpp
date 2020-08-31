#include <iostream>
#include <queue>
using namespace std;

int map[501][501] = {0, };
int temp[501][501] = {0, };
int N;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int answer;
queue<int> qx;
queue<int> qy;

void bfs(int i, int j) {
    for(int i =1; i <= N; i++) {
        for(int j = 1; j <=N; j++) {
            temp[i][j] = 1;
        }
    }
    
    qx.push(i);
    qy.push(j);
    
    int temp_x, temp_y;
    while(!qx.empty() && !qy.empty()) {
        temp_x = qx.front();
        qx.pop();
		temp_y = qy.front();
        qy.pop();
        for(int i = 0; i < 4; i++) {
            int xx = temp_x + dx[i];
            int yy = temp_y + dy[i];
            if(map[xx][yy] > map[temp_x][temp_y] ) {
                qx.push(xx);
                qy.push(yy);

                temp[xx][yy] = temp[temp_x][temp_y] + 1;
                if(answer < temp[xx][yy])
                    answer = temp[xx][yy];
            }
        }
        
    }
//        for(int j = 1; j <= N; j++) {
//            for(int k = 1; k <= N; k++) {
//                cout << temp[j][k] << " ";
//                if (answer < temp[j][k])
//                    answer = temp[j][k];
//            }
//            cout << '\n';
//        }
//        cout <<'\n';
}
int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cin >> N;
        if( N > 99) {
            answer = 1;
        }
        else {
            answer = 0;
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                cin >> map[j][k];
            }
        }
        
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
            
                bfs(j, k);
                
            }
        }
        }
        
     
        cout << "#" << i << " " << answer << '\n';
    }
    
    return 0;
}
