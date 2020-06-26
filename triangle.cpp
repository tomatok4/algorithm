#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> t;
    vector<int> temp;
    t.push_back(triangle[0]);
    
    for(int i = 1; i < triangle.size(); i++) {
        temp.push_back(t[i-1][0] + triangle[i][0]);
        temp.push_back(t[i-1][0] + triangle[i][1]);
        for(int j =1; j <triangle[i-1].size();j++) {
            temp[j] = max(temp[j], t[i-1][j] + triangle[i][j]);       
            temp.push_back(t[i-1][j] + triangle[i][j+1]);
        }
        t.push_back(temp);
        temp.clear();
    }
    for(int i = 0; i < t[t.size()-1].size();i++)
        answer = max(answer, t[t.size()-1][i]);
    for(auto s :t ) {
        for(auto q : s)
            cout << q << " ";
        cout << endl;
    }

    return answer;
}

int main() {

    vector<vector<int>> input = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4},{4, 5, 2, 6, 5}}	;

    int answer = solution(input);
    cout << answer << endl;
    return 0;
}