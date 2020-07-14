#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> c) {
    int answer = 0;
    bool check[50] = {false, };
    int last = c.size() - 1;
    while(1) {
        for(int i = 0 ; i < c.size(); i++) {
            if(c[i][0] == 'D') {
                return answer;
            }
            else {
                if(c[i][0] == ' ') 
                    continue;
                else {
                    if(check[i] == true || i == last) {
                        string temp = c[i].substr(1, c[i].length());
                        c[i] = temp;
                        cout << c[i] << endl;
                        check[i] = false;
                    }
                    else {
                        check[i] = true;
                    }
                    
                }
            }
            answer++;
        }
        
    }
    cout << c[1] << endl;

    return answer;
}

int main() {
    vector<string> c = {"AB","CD", "E"};
    
    int answer = solution(c);

    cout << answer << endl;

    return 0;
}