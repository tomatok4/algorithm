#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int N, vector<vector<int>> simulation_data) {
    int answer = 0;
    int time = 0;
    int chang[21] = {0,};
    int customer = 0;
    while(1) {
        
        for(int i= 0; i < N; i++) {
            if(chang[i] == 0 && simulation_data[customer][0] == time) {
                chang[i] = simulation_data[customer][1];
                customer++;
                break;
            }
            
            if( i == N)
                answer++;
        }
        
        for(int i= 0; i < N; i++) {
            if(chang[i] == 1 && simulation_data[customer][0] == time) {
                chang[i] = 0;
            }
        }
        
        answer++;
        
        if(customer == simulation_data.size() +1)
            break;
        cout << time << endl;
        time++;
    }
    
    return answer;
}

int main() {

    vector<vector<int>> simulation_data = {{0, 3}, {2,5}, {4,2}, {5,3}};
    solution(2, simulation_data);

    return 0;
}