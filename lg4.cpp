#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> a[100001];
bool check[100001];
int c;
void bfs(int start ,int end) {
    if(start == end ) {
        c = 1;
        return;        
    }
    c = 1;
    check[start] = true;

    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        c++;
        for(int y : a[x]) {
            if(!check[y]) {
                check[y] = true;
                if(y == end) {
                    
                    return;
                }
                q.push(y);
            }
        }
    }
}
vector<int> solution(int N, vector<vector<int>> directory, vector<vector<int>> query) {
    vector<int> answer;
    for(int i=0 ; i<100001;i++) {
        a[i].clear();
    }

    for(int i = 0; i < directory.size();i++) {
        a[directory[i][0]].push_back(directory[i][1]);
        a[directory[i][1]].push_back(directory[i][0]);
    }
    for(int i = 0; i < query.size(); i++) {
        bfs(query[i][0], query[i][1]);
        for(int j = 1; j <= N; j++)
            check[j] = false;
        answer.push_back(c);
    }
    return answer;
}