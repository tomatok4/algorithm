#include <iostream>
#include <stack>

using namespace std;


int main(int argc, char** argv) {
    int test_case;
    int T;
    int answer;
    string frog;
    cin >> T;
    
    for(test_case = 1; test_case <= T; test_case++) {
        cin >> frog;
        answer = 0;
        int c = 1;
        int first = 0;
        int last = 0;
        if(frog.length() % 5 != 0) {
            answer = -1;
            printf("#%d %d\n", test_case, answer);
            continue;
        }
        if(frog.at(0)!='c') {
            answer = -1;
        }
        if(answer != -1) {
            stack<char> s[501];
            for(auto it = frog.begin(); it!=frog.end(); it++) {
                bool check = false;
                if(*it=='c' && first == 0) {
                        s[c].push('c');
                        check = true;
                        first = 1;
                }
                else if(*it=='c' && last == 0) {
                    c++;
                    s[c].push('c');
                    check = true;
                }
                else if(*it=='c') {
                    
                    s[last].push('c');
                    check = true;
                    last = 0;
                }
                else if(*it=='r') {
                    for(int i = 1; i <= c; i++) {
                        if(!s[i].empty()) {
                            if(s[i].top() == 'c'){
                                s[i].pop();
                                s[i].push('r');
                                check = true;
                                break;
                            }
                        }
                    }   
                }
                else if(*it=='o') {
                    for(int i = 1; i <= c; i++) {
                        if(!s[i].empty()) {
                            if(s[i].top() == 'r'){
                                s[i].pop();
                                s[i].push('o');
                                check = true;
                                break;
                            }
                        }
                        
                    }
                        
                }
                else if(*it=='a') {
                    for(int i = 1; i <= c; i++) {
                        if(!s[i].empty()) {
                            if(s[i].top() == 'o'){
                                    s[i].pop();
                                    s[i].push('a');
                                    check = true;
                                    break;
                            }
                        }
                    }
                        
                }
                else if(*it=='k') {
                    for(int i = 1; i <= c; i++) {
                        if(!s[i].empty()) {
                            if(s[i].top() == 'a'){
                                s[i].pop();
                                check = true;
                                last = i;
                                break;
                            }
                        }
                        
                    }
                        
                }
                if(check == false) {
                    answer = -1;
                    break;
                }
            
            }
            answer = c;
            for(int i = 1; i <= c; i++) {
                if(!s[i].empty()) {
                    answer = -1;
                    break;
                }
                    
            }
        }
        
        printf("#%d %d\n", test_case, answer);
    }
    return 0;
}