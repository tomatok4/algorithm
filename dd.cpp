#include <iostream>
#include <cstring>
using namespace std;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main() {
    int a, b;
    int c = 0;
    int m, d;
    cin >> a >> b;
    
    for(int i = 1; i < a; i++) {
        for(int j = 0; j < days[i]; j++) {
            c++;
            if(c == 7)
                c = 0;
        }
    }
    d = b - 1;
    for(int i = 0; i < d; i++) {
        c++;
            if(c == 7)
                c = 0;
    }
    
    cout << day[c] << '\n';
    return 0;
}
