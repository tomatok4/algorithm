
#include <iostream>
using namespace std;

int p[1000];
int pn=0;
bool c[1001];
int m, n;
int main(void) {
    cin >> m >> n ;
    for ( int i =2; i <=n; i++) {
        if (c[i] == false) {
            p[pn++] = i;
            for ( int j = i*i; j <=n; j+=i) {
                 c[j] = true;
            }
        }
    }
    for(int i = 0; i <= pn; i++) {
        if(p[i] >= m)
            cout << p[i] << '\n';    
    }
    
    return 0;
}
