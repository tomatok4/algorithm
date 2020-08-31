#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<vector<int> > land)
{
    vector<vector<int>> temp(100001, (vector<int>(4, 0)));
    int rowOfLand = land.size();
    int answer = 0;
         
    for(int i = 0 ; i < 4 ; i++) {
        temp[0][i] = land[0][i];
    }
    for(int i = 1; i < rowOfLand ; i++) {
        for(int j = 0 ; j < 4 ; j++) {
            for(int k = 0 ; k < 4 ; k++) {
                if(j!=k) {
                    temp[i][j] = max(temp[i][j], temp[i-1][k] + land[i][j]);
                }                    
            }
        }
    }

    for(int i = 0 ; i < 4 ; i++) {
        answer = max(answer, temp[rowOfLand-1][i]);
    }
    // for(int i = 0; i < 4; i++) {
    //     for(auto j : temp[i]) {
    //         cout << j <<" ";
    //     }
    //     cout << endl;
    // }
    return answer;
}

int main() {

    vector<vector<int>> land = {{1,2,3,5},{5,6,7,100},{4,3,2,1}};
    int answer = solution(land);
    cout << answer << endl;
    return 0;
}