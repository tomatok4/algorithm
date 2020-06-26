#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main(void) {
    unsigned int a, w;
    int c;

    scanf("%d", &c);
    for(int i =0; i < c; ++i) {
        scanf("%u", &a);
        w = (a << 24) | ((a << 8) & 0x00FF0000) | ((a >> 8) & 0x0000FF00) | ((a >> 24) & 0x000000FF);
        printf("%u\n",w);
    }
    

    return 0;
}