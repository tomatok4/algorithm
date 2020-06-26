#include <iostream>
#include <queue>
#include <set>

using namespace std;
int main() {
    int T, N, K = 1;
    
    int color[10001] = {0,};
    int point;
    int answer;
    
    cin >> T;
    for( int i = 1; i <= T; i++) {
        cin >> N >> K;
        set<int> check;
        queue<int> temp; //갱신
        queue<int> number; // 없는숫자
        int count[K+1] = {0, };
        point = 1; // 가리키고 있는 숫자?
        answer = 0;
        
        for(int j = 1; j <= N; j++) {
            cin >> color[j];
             
            if(color[j] != 0) {
                check.insert(color[j]);
            }
        }
        for(int l = 1; l <= K; l++) {
           if(check.find(l) == check.end()) {
                number.push(l);
           }
        }
        
        if(number.size() == K) {
                answer = N-K+1;   
        }
        
        else {
            for(int j = 1; j <= N; j++) {
                if(color[j] == 0 && j != N) {
                    if(color[j+1] == 0) {
                        temp.push(point);
                    }
                    else {
                        temp.push(point);
                        if(point < color[j+1]) {
                            if(!number.empty() && number.front() < color[j+1]) {
                                point = number.front();
                                number.pop();
                                temp.push(point);
                            }
                            else {
                                point = color[j+1];
                                temp.push(point);
                            }
                            
                        }
                        
                    }
                }
                else if(color[j] ==0 && j == N) {
                    temp.push(point);
                }
                
                else {
                    if(color[j+1] == 0) {
                        temp.push(color[j]);
                        int end = j+1;
                        if(point < K)
                            point++;
                        while(color[end] ==0 && end != N+1) {
    
                            end++;
                            if(point-1 == color[end]) {
                                point--;
                                break;
                            }
                        }
                    }
                    else {
                        temp.push(color[j]);
                        point = color[j];
                    }
                    
                }
            
            }
            int t = 0;
            while(!temp.empty()) {
                t = temp.front();
                
                temp.pop();
                count[t]++;
            }
            answer = count[1];
            for(int j =2; j<= K; j++) {
                if(answer < count[j]) {
                    answer = count[j];
                }
            }

        }
        cout << "#" << i << " " << answer <<'\n';
    }
    
    return 0;
}
