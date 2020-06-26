#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int test_case;
    int T;
    string frog;

    cin >> T;
    
    for(test_case = 1; test_case <= T; test_case++) {
        cin >> frog;
        bool flag = true;

        int check[5] = {0,};

        for (int i = 1; i <= frog.length(); i++) {
            if (frog[i - 1] == 'c') {
                if (check[4] == 0) {
                    check[0]++;
                } else {
                    check[4]--;
                    check[0]++;
                }
            } else if(frog[i-1] == 'r'){
                if(check[0] == 0) flag = false;
                check[0]--;
                check[1]++;
            } else if(frog[i-1] == 'o'){
                if(check[1] == 0) flag = false;
                check[1]--;
                check[2]++;
            } else if(frog[i-1] == 'a'){
                if(check[2] == 0) flag = false;
                check[2]--;
                check[3]++;
            } else if(frog[i-1] == 'k'){
                if(check[3] == 0) flag = false;
                check[3]--;
                check[4]++;
            }
        }

        for(int i=1;i<=4;i++){
            if(check[i-1] != 0){
                flag = false;
            }
        }

        if(flag == true){
            cout << "#"<< test_case << " " << check[4] << '\n';
        } else{
            cout << "#"<< test_case << " " << -1 << '\n';
        }
    }

    return 0;
}